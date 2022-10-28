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
  int weight;       // can be double or other numeric type
  Edge(int t, int w)
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
  void add_edge(int u, int v, int weight)
  {
    nbr[u].push_back(Edge(v, weight));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<int> &D, vector<int> &P)
{
  typedef pair<int,int> pii;

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
      int weight = it->weight + next.first;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

int get_path(int v, const vector<int> &P, vector<int> &path)
{
  path.clear();
  path.push_back(v);
  while (P[v] != -1) {
    v = P[v];
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  return path.size();
}

int R,C;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

bool bounds(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C;
}

int node(int i, int j) {
	return (i*C)+j;
}

int main() {
	cin>>R>>C;
	vector<string> B(R);
	for(string &s:B)
		cin>>s;

	pii J;
	vector<pii> F;

	Graph G((R*C)+1);
	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; ++j) {
			if(B[i][j] != '#') {
				if(B[i][j] == 'J')
					J = {i,j};
				if(B[i][j] == 'F')
					F.emplace_back(i,j);
				
				for(int k=0; k<4; ++k) {
					int i2 = i+dy[k];
					int j2 = j+dx[k];
					if(bounds(i2,j2) && B[i2][j2] != '#') {
						G.add_edge(node(i,j),node(i2,j2),1);
						G.add_edge(node(i2,j2),node(i,j),1);
					}
				}
			}
		}
	}

	for(auto p:F)
		G.add_edge(R*C, node(p.fst,p.snd), 0);

	vi JD,JP,FD,FP;
	dijkstra(G, node(J.fst,J.snd), JD,JP);
	dijkstra(G, R*C, FD,FP);

	int ans = INT_MAX;
	for(int i=0; i<R; ++i) {
		for(int j=0; j<C; j+=((i==0||i==R-1)?1:C-1)) {
			if(B[i][j] != '#' && JD[node(i,j)] != -1) {
				if(JD[node(i,j)] < FD[node(i,j)] || FD[node(i,j)] == -1)
					ans = min(ans, JD[node(i,j)]);
			}
		}
	}
	if(ans != INT_MAX)
		cout<<ans+1<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
}
