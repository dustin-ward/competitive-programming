// Bipartite Graph
// Network flow
#include <bits/stdc++.h>
using namespace std;

struct Edge;
typedef list<Edge>::iterator EdgeIter;

struct Edge {
  int to;
  int cap;
  int flow;
  bool is_real;
  EdgeIter partner;
  
  Edge(int t, int c, bool real = true)
    : to(t), cap(c), flow(0), is_real(real)
  {};

  int residual() const
  {
    return cap - flow;
  }
};

struct Graph {
  list<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new list<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: this routine adds an edge to the graph with the specified capacity,
  // as well as a residual edge.  There is no check on duplicate edge, so it
  // is possible to add multiple edges (and residual edges) between two
  // vertices
  void add_edge(int u, int v, int cap)
  {
    nbr[u].push_front(Edge(v, cap));
    nbr[v].push_front(Edge(u, 0, false));
    nbr[v].begin()->partner = nbr[u].begin();
    nbr[u].begin()->partner = nbr[v].begin();
  }
};

void push_path(Graph &G, int s, int t, const vector<EdgeIter> &path, int flow)
{
  for (int i = 0; s != t; i++) {
    if (path[i]->is_real) {
      path[i]->flow += flow;
      path[i]->partner->cap += flow;
    } else {
      path[i]->cap -= flow;
      path[i]->partner->flow -= flow;
    }
    s = path[i]->to;
  }
}

// the path is stored in a peculiar way for efficiency: path[i] is the
// i-th edge taken in the path.
int augmenting_path(const Graph &G, int s, int t, vector<EdgeIter> &path,
		    vector<bool> &visited, int step = 0)
{
  if (s == t) {
    return -1;
  }
  for (EdgeIter it = G.nbr[s].begin(); it != G.nbr[s].end(); ++it) {
    int v = it->to;
    if (it->residual() > 0 && !visited[v]) {
      path[step] = it;
      visited[v] = true;
      int flow = augmenting_path(G, v, t, path, visited, step+1);
      if (flow == -1) {
	return it->residual();
      } else if (flow > 0) {
	return min(flow, it->residual());
      }
    }
  }
  return 0;
}

// note that the graph is modified
int network_flow(Graph &G, int s, int t)
{
  vector<bool> visited(G.num_nodes);
  vector<EdgeIter> path(G.num_nodes);
  int flow = 0, f;

  do {
    fill(visited.begin(), visited.end(), false);
    if ((f = augmenting_path(G, s, t, path, visited)) > 0) {
      push_path(G, s, t, path, f);
      flow += f;
    }
  } while (f > 0);
  
  return flow;
}

void printG(Graph &G, int n) {
    cout<<"GRAPH"<<endl;
    for(int i=0; i<n*2+2; i++) {
        for(auto e:G.nbr[i])
            cout<<i<<" -> "<<e.to<<" flow: "<<e.flow<<" cap: "<<e.cap<<endl;
    }
}

void printB(string buttons[], int n) {
    cout<<"\nButtons"<<endl;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        cout<<buttons[i][j]<<" ";
      }
      cout<<endl;
    }
}

bool buildGraph(Graph &G, int n, string buttons[], int cap) {
    for(int i=0; i<n*2+2; i++)
      G.nbr[i].clear();
    
    int sink = n*2+1;
    for(int i=0; i<n; i++) {
        // cout<<0<<" -> "<<i+1<<endl;
        G.add_edge(0, i+1, cap);
        // cout<<n+i+1<<" -> "<<sink<<endl;
        G.add_edge(n+i+1, sink, cap);

        for(int j=0; j<n; j++) {
            if(buttons[i][j] == 'Y') {
                // cout<<i+1<<" -> "<<n+j+1<<endl;
                G.add_edge(i+1, n+j+1, 1);
            }
        }
    }
    int f = network_flow(G, 0, sink);
    // printG(G, n);
    return f == n * cap;
}

int main() {
    int n; cin>>n;
    
    string buttons[80];
    for(int i=0; i<n; i++) {
      string s; cin>>buttons[i];
    }
    // printB(buttons, n);

    // Build Graph
    Graph G(n*2+2);
    
    int low=0, high = 1;
    while(buildGraph(G, n, buttons, high))
      high *= 2;
    while(high-low > 1) {
      int mid = (low+high)/2;
      if(buildGraph(G, n, buttons, mid))
        low = mid;
      else
        high = mid;
    }

    cout<<low<<endl;
    buildGraph(G, n, buttons, low);
    for(int i=1; i<=n; i++) {
      for(auto &e:G.nbr[i]) {
        if(!e.is_real || e.flow > 0) continue;
        buttons[i-1][(e.to-n)-1] = 'N';
        // printB(buttons, n);
      }
    }

    for(int i=0; i<low; i++) {
      buildGraph(G, n, buttons, 1);
      vector<pair<int,int>> order;
      for(int j=1; j<=n; j++) {
        for(auto &e:G.nbr[j]) {
          if (!(e.flow > 0 && e.is_real)) continue;
          order.emplace_back(e.to-n,j);
          buttons[j-1][(e.to-n)-1] = 'N';
          // printB(buttons, n);
        }
      }
      sort(order.begin(), order.end());
      for(auto i:order)
        cout<<i.second<<" ";
      cout<<endl;
    }
}