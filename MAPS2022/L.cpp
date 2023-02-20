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

int N,M,C;
int UP=0;
int RIGHT=1;
int DOWN=2;
int LEFT=3;

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

bool bounds(int i, int j, int dir) {
	if(i >= 0 && i < N && j >= 0 && j < M) {
		if(!i && dir==UP)
			return false;
		if(i==N-1 && dir==DOWN)
			return false;
		if(!j && dir==LEFT)
			return false;
		if(j==M-1 && dir==RIGHT)
			return false;
		return true;	
	}
	return false;
}

int getNode(int i, int j, int dir) {
	return (i*N)+(j*4)+dir;
}

struct Cnstr {
	int t;
	int r;
	int l;
};

int main() {
	cin>>N>>M>>C;
	int xP,yP,xD,yD; cin>>xP>>yP>>xD>>yD;
	
	Graph G(N*M*4);

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			for(int k=0; k<4; ++k) {
				int i2=i+dy[k];
				int j2=j+dx[k];
				int k2=(k+2)%4;
				if(bounds(i,j,k) && bounds(i2,j2,k2)) {
					int n1 = getNode(i,j,k);
					int n2 = getNode(i2,j2,k2);
					G.add_edge(n1,n2,1);
				}
			}	
		}
	}

	map<pii,int> mp;
	vector<Cnstr> cV(C);
	for(int c=0; c<C; ++c) {
		int i,j,t,r,l; cin>>i>>j>>t>>r>>l;
		Cnstr cn = {t,r,l};
		mp.insert({{i,j},c});
		cV[c] = cn;
	}

	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			Cnstr cn;
			if(mp.find({i,j}) != mp.end())
				cn = cV[mp[make_pair(i,j)]];
			else
				cn = {1,2,3};
			for(int k=0; k<4; ++k) {
				int n1 = getNode(i,j,k);
				int kThru = (k+2)%4;
				if(bounds(i,j,k) && bounds(i,j,kThru)) {
					int n2 = getNode(i,j,kThru);
					G.add_edge(n1,n2,cn.t);
				}
				int kLeft = (k+1)%4;
				if(bounds(i,j,k) && bounds(i,j,kLeft)) {
					int n2 = getNode(i,j,kLeft);
					G.add_edge(n1,n2,cn.l);
				}
				int kRight = (k+3)%4;
				if(bounds(i,j,k) && bounds(i,j,kRight)) {
					int n2 = getNode(i,j,kRight);
					G.add_edge(n1,n2,cn.r);
				}
			}
		}
	}

	
}
