use std::io;
use std::convert::TryInto;

/// Represents a union of disjoint sets. Each set's elements are arranged in a
/// tree, whose root is the set's representative.
pub struct DisjointSets {
    parent: Vec<usize>,
}

impl DisjointSets {
    /// Initializes disjoint sets containing one element each.
    pub fn new(size: usize) -> Self {
        Self {
            parent: (0..size).collect(),
        }
    }

    /// Finds the set's representative. Do path compression along the way to make
    /// future queries faster.
    pub fn find(&mut self, u: usize) -> usize {
        let pu = self.parent[u];
        if pu != u {
            self.parent[u] = self.find(pu);
        }
        self.parent[u]
    }

    /// Merges the sets containing u and v into a single set containing their
    /// union. Returns true if u and v were previously in different sets.
    pub fn merge(&mut self, u: usize, v: usize) -> bool {
        let (pu, pv) = (self.find(u), self.find(v));
        self.parent[pu] = pv;
        pu != pv
    }
}

/// A compact graph representation. Edges are numbered in order of insertion.
/// Each adjacency list consists of all edges pointing out from a given vertex.
pub struct Graph {
    /// Maps a vertex id to the first edge in its adjacency list.
    first: Vec<Option<usize>>,
    /// Maps an edge id to the next edge in the same adjacency list.
    next: Vec<Option<usize>>,
    /// Maps an edge id to the vertex that it points to.
    endp: Vec<usize>,
}

impl Graph {
    /// Initializes a graph with vmax vertices and no edges. To reduce
    /// unnecessary allocations, emax_hint should be close to the number of
    /// edges that will be inserted.
    pub fn new(vmax: usize, emax_hint: usize) -> Self {
        Self {
            first: vec![None; vmax],
            next: Vec::with_capacity(emax_hint),
            endp: Vec::with_capacity(emax_hint),
        }
    }

    /// Returns the number of vertices.
    pub fn num_v(&self) -> usize {
        self.first.len()
    }

    /// Returns the number of edges, double-counting undirected edges.
    pub fn num_e(&self) -> usize {
        self.endp.len()
    }

    /// Adds a directed edge from u to v.
    pub fn add_edge(&mut self, u: usize, v: usize) {
        self.next.push(self.first[u]);
        self.first[u] = Some(self.num_e());
        self.endp.push(v);
    }

    /// An undirected edge is two directed edges. If edges are added only via
    /// this funcion, the reverse of any edge e can be found at e^1.
    pub fn add_undirected_edge(&mut self, u: usize, v: usize) {
        self.add_edge(u, v);
        self.add_edge(v, u);
    }

    /// If we think of each even-numbered vertex as a variable, and its
    /// odd-numbered successor as its negation, then we can build the
    /// implication graph corresponding to any 2-CNF formula.
    /// Note that u||v == !u -> v == !v -> u.
    pub fn add_two_sat_clause(&mut self, u: usize, v: usize) {
        self.add_edge(u ^ 1, v);
        self.add_edge(v ^ 1, u);
    }

    /// Gets vertex u's adjacency list.
    pub fn adj_list(&self, u: usize) -> AdjListIterator {
        AdjListIterator {
            graph: self,
            next_e: self.first[u],
        }
    }
}

/// An iterator for convenient adjacency list traversal.
pub struct AdjListIterator<'a> {
    graph: &'a Graph,
    next_e: Option<usize>,
}

impl<'a> Iterator for AdjListIterator<'a> {
    type Item = (usize, usize);

    /// Produces an outgoing edge and vertex.
    fn next(&mut self) -> Option<Self::Item> {
        self.next_e.map(|e| {
            let v = self.graph.endp[e];
            self.next_e = self.graph.next[e];
            (e, v)
        })
    }
}

/// Representation of a network flow problem with (optional) costs.
pub struct FlowGraph {
    /// Owned graph, managed by this FlowGraph object.
    pub graph: Graph,
    /// Edge capacities.
    pub cap: Vec<i64>,
    /// Edge cost per unit flow.
    pub cost: Vec<i64>,
}

impl FlowGraph {
    /// An upper limit to the flow.
    const INF: i64 = 0x3f3f_3f3f_3f3f_3f3f;

    /// Initializes an flow network with vmax vertices and no edges.
    pub fn new(vmax: usize, emax_hint: usize) -> Self {
        Self {
            graph: Graph::new(vmax, 2 * emax_hint),
            cap: Vec::with_capacity(2 * emax_hint),
            cost: Vec::with_capacity(2 * emax_hint),
        }
    }

    /// Adds an edge with specified directional capacities and cost per unit of
    /// flow. If only forward flow is allowed, rcap should be zero.
    pub fn add_edge(&mut self, u: usize, v: usize, cap: i64, rcap: i64, cost: i64) {
        self.cap.push(cap);
        self.cap.push(rcap);
        self.cost.push(cost);
        self.cost.push(-cost);
        self.graph.add_undirected_edge(u, v);
    }

    /// Dinic's algorithm to find the maximum flow from s to t where s != t.
    /// Generalizes the Hopcroft-Karp maximum bipartite matching algorithm.
    /// V^2E in general, min(V^(2/3),sqrt(E))E when all edges are unit capacity,
    /// sqrt(V)E when all vertices are unit capacity as in bipartite graphs.
    ///
    /// # Panics
    ///
    /// Panics if the maximum flow is 2^63 or larger.
    pub fn dinic(&self, s: usize, t: usize) -> (i64, Vec<i64>) {
        let mut flow = vec![0; self.graph.num_e()];
        let mut max_flow = 0;
        loop {
            let dist = self.dinic_search(s, &flow);
            if dist[t] == Self::INF {
                break;
            }
            // Keep track of adjacency lists to avoid revisiting blocked edges.
            let mut adj_iters = (0..self.graph.num_v())
                .map(|u| self.graph.adj_list(u).peekable())
                .collect::<Vec<_>>();
            max_flow += self.dinic_augment(s, t, Self::INF, &dist, &mut adj_iters, &mut flow);
        }
        (max_flow, flow)
    }

    // Compute BFS distances to restrict attention to shortest path edges.
    fn dinic_search(&self, s: usize, flow: &[i64]) -> Vec<i64> {
        let mut dist = vec![Self::INF; self.graph.num_v()];
        let mut q = ::std::collections::VecDeque::new();
        dist[s] = 0;
        q.push_back(s);
        while let Some(u) = q.pop_front() {
            for (e, v) in self.graph.adj_list(u) {
                if dist[v] == Self::INF && flow[e] < self.cap[e] {
                    dist[v] = dist[u] + 1;
                    q.push_back(v);
                }
            }
        }
        dist
    }

    // Pushes a blocking flow that increases the residual's s-t distance.
    fn dinic_augment(
        &self,
        u: usize,
        t: usize,
        f: i64,
        dist: &[i64],
        adj: &mut [::std::iter::Peekable<AdjListIterator>],
        flow: &mut [i64],
    ) -> i64 {
        if u == t {
            return f;
        }
        let mut df = 0;

        while let Some(&(e, v)) = adj[u].peek() {
            let rem_cap = (self.cap[e] - flow[e]).min(f - df);
            if rem_cap > 0 && dist[v] == dist[u] + 1 {
                let cf = self.dinic_augment(v, t, rem_cap, dist, adj, flow);
                flow[e] += cf;
                flow[e ^ 1] -= cf;
                df += cf;
                if df == f {
                    break;
                }
            }
            // The current edge is either saturated or blocked.
            adj[u].next();
        }
        df
    }
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line);
    let t = line.trim().parse::<u32>().unwrap();

    for _ in 0..t {
        line = String::new();
        io::stdin().read_line(&mut line);
        let [c,d,v]: [u32; 3] = line
            .split_whitespace()
            .map(|s| s.parse::<u32>())
            .collect::<Result<Vec<u32>,_>>()
            .unwrap()
            .try_into()
            .unwrap();

        let mut cat_lovers = Vec::new();
        let mut dog_lovers = Vec::new();
        for _ in 0..v {
            line = String::new();
            io::stdin().read_line(&mut line);
            let [s1,s2]: [String; 2] = line
                .split_whitespace()
                .map(|s| String::from(s))
                .collect::<Vec<String>>()
                .try_into()
                .unwrap();

            if s1.starts_with('C') {
                cat_lovers.push((s1,s2));
            } else {
                dog_lovers.push((s1,s2));
            }
        }

        let start_cat = 0;
        let start_dog = cat_lovers.len();
        let src = start_dog+dog_lovers.len();
        let snk = src+1;

        let mut graph = FlowGraph::new((v+2) as usize, (v+2) as usize);
        for i in start_cat..start_dog {
            graph.add_edge(src as usize, i as usize, 1, 0, 0);
        }
        for i in start_dog..src {
            graph.add_edge(i as usize, snk as usize, 1, 0, 0);
        }

        for (i,(cc,cd)) in cat_lovers.iter().enumerate() {
            for (j,(dd,dc)) in dog_lovers.iter().enumerate() {
                if cc == dc || dd == cd {
                    graph.add_edge((start_cat as usize)+i, (start_dog as usize)+j, 1, 0,0);
                }
            }
        }

        let (flow_amt, _) = graph.dinic(src as usize, snk as usize);
        println!("{}", (v as i64)-flow_amt);
    }
}
