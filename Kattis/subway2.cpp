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
  double weight;       // can be double or other numeric type
  Edge(int t, double w)
    : to(t), weight(w) { }
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
  void add_edge(int u, int v, double weight)
  {
    nbr[u].push_back(Edge(v, weight));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<double> &D, vector<int> &P)
{
  typedef pair<double,int> pii;

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
      double weight = it->weight + next.first;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

const double WALK = 10000.0 / 60.0;
const double TRAIN = 40000.0 / 60.0;

struct Stop {
    int x;
    int y;
    int l;
};

int main() {
    int X,Y,X2,Y2;
    cin>>X>>Y>>X2>>Y2;
    
    Graph G(203);
    double dis = sqrt((X-X2)*(X-X2) + (Y-Y2)*(Y-Y2));
    G.add_edge(201,202,dis / WALK);
    G.add_edge(202,201,dis / WALK);
    // cout<<"E: "<<200<<" <-> "<<201<<" ("<<dis/WALK<<")"<<endl;

    vector<Stop> stops;
    int sX,sY;
    int count = 0;
    while(cin>>sX>>sY) {
        if(sX==-1&&sY==-1) {
            count++;
            continue;
        }
        stops.push_back({sX,sY,count});
    }

    for(int i=0; i<sz(stops); i++) {
        auto &[x1,y1,l1] = stops[i];
        for(int j=i+1; j<sz(stops); j++) {
            auto &[x2,y2,l2] = stops[j];
            dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

            if(l1 == l2) dis /= TRAIN;
            else dis /= WALK;

            G.add_edge(i,j,dis);
            G.add_edge(j,i,dis);
            // cout<<"E: "<<i<<" <-> "<<j<<" ("<<dis<<")"<<endl;
            
        }
        dis = sqrt((x1-X)*(x1-X) + (y1-Y)*(y1-Y));
        G.add_edge(201,i,dis/WALK);
        G.add_edge(i,201,dis/WALK);
        // cout<<"E: "<<201<<" <-> "<<i<<" ("<<dis/WALK<<")"<<endl;

        dis = sqrt((x1-X2)*(x1-X2) + (y1-Y2)*(y1-Y2));
        G.add_edge(202,i,dis/WALK);
        G.add_edge(i,202,dis/WALK);
        // cout<<"E: "<<202<<" <-> "<<i<<" ("<<dis/WALK<<")"<<endl;
    }

    vector<double> D;
    vi P;
    dijkstra(G,201,D,P);

    cout<<(int)round(D[202])<<endl;
}
