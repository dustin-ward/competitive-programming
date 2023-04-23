#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

const double PI = acos(-1);
double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

struct Edge {
  int to;
  ll t;
  ll P;
  ll d;
  Edge(int to, ll t, ll P, ll d)
    : to(to), t(t), P(P), d(d) { }
};
  
typedef vector<Edge>::iterator EdgeIter;

struct Graph {
  vector<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new vector<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: There is no check on duplicate edge, so it is possible to
  // add multiple edges between two vertices
  //
  // If this is an undirected graph, be sure to add an edge both
  // ways
  void add_edge(int u, int v, ll t, ll P, ll d)
  {
    nbr[u].push_back(Edge(v, t, P, d));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<ll> &D, vector<ll> &P)
{
  typedef pair<ll,ll> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;

  D.resize(n);
  P.resize(n);
  fill(D.begin(), D.end(), -1);
  fill(P.begin(), P.end(), -1);

  D[src] = 0;
  fringe.push(make_pair(D[src], src));

  while (!fringe.empty()) {
    pii next = fringe.top();
    fringe.pop();
    int u = next.second;
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      int weight = INT_MAX;
      if(next.fst <= it->t && it->P == 0)
          weight = it->t + it->d;
      else if(it->P > 0) {
          weight = it->t + max(0LL, next.fst-it->t) / it->P * it->P;
          if(weight < next.fst)
              weight += it->P;
          weight += it->d;
      }
      // ll wait = INT_MAX;
      // if(it->P == 0) {
      //   if(next.fst > it->t) continue;
      //   wait = it->t - next.fst;
      // } else {
      //   if((next.fst - it->t) % it->P)
      //     wait = it->P - ((next.fst-it->t) % it->P);
      // }
      // ll weight = next.fst + it->d + wait;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

int main() {
    int N,M,Q,S; 

    while(cin>>N>>M>>Q>>S && N) {
        Graph G(N);
        for(int i=0; i<M; i++) {
            ll u,v,t,P,d; cin>>u>>v>>t>>P>>d;
            G.add_edge(u,v,t,P,d);
        }

        vector<ll> D,P;
        dijkstra(G,S,D,P);

        for(int i=0; i<Q; i++) {
            int q; cin>>q;
            if(D[q] == -1 || D[q] >= INT_MAX)
                cout<<"Impossible"<<endl;
            else
                cout<<D[q]<<endl;
        }
        cout<<endl;
    }
}
