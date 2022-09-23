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

const int MAX_VARS = 500 * 500 * 4;          // maximum number of variables
const int MAX_NODES = 2*MAX_VARS;

struct Graph{
  int numNodes;
  vector<int> adj[MAX_NODES];
  void clear(){
    numNodes = 0;
    for(int i=0;i<MAX_NODES;i++)
      adj[i].clear();
  }
  void add_edge(int u,int v){
    if(find(adj[u].begin(),adj[u].end(),v) == adj[u].end())
      adj[u].push_back(v);
  }
};

int po[MAX_NODES],comp[MAX_NODES];
int num_scc;

void DFS(int v, const Graph& G, int& C, stack<int>& P,stack<int>& S){
  po[v] = C++;
  
  S.push(v);  P.push(v);
  for(unsigned int i=0;i<G.adj[v].size();i++){
    int w = G.adj[v][i];
    if(po[w] == -1){
      DFS(w,G,C,P,S);
    } else if(comp[w] == -1){
      while(!P.empty() && (po[P.top()] > po[w]))
	P.pop();
    }
  }
  if(!P.empty() && P.top() == v){
    while(!S.empty()){
      int t = S.top();
      S.pop();
      comp[t] = num_scc;
      if(t == v)
	break;
    }
    P.pop();
    num_scc++;
  }
}

int SCC(const Graph& G){
  num_scc = 0;
  int C = 1;
  stack<int> P,S;
  fill(po,po+G.numNodes,-1);
  fill(comp,comp+G.numNodes,-1);
  for(int i=0;i<G.numNodes;i++)
    if(po[i] == -1)
      DFS(i,G,C,P,S);
  
  return num_scc;
}


int VAR(int i) { return 2*i; }
int NOT(int i) { return i ^ 1; }

void add_clause(Graph &G, int v, int w) { // adds (v || w)
  if (v == NOT(w)) return;
  G.add_edge(NOT(v), w);
  G.add_edge(NOT(w), v);
}

bool twoSAT(const Graph &G, bool val[]) {   // assumes graph is built
  SCC(G);
  for (int i = 0; i < G.numNodes; i += 2) {
    if (comp[i] == comp[i+1]) return false;
    val[i/2] = (comp[i] < comp[i+1]);
  }
  return true;
}


// Declare this as a global variable if MAX_NODES is large to
//   avoid Runtime Error.
Graph G;
int N,M;

bool bounds(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int main() {
	cin>>N>>M;
	vector<vector<char>> V(N, vector<char>(M));
	vector<pii> b,w;
	int B=0, W=0;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			cin>>V[i][j];
			B += V[i][j] == 'B';
			W += V[i][j] == 'W';
			
			if(V[i][j] == 'B')
				b.emplace_back(i,j);
			if(V[i][j] == 'W')
				w.emplace_back(i,j);
		}
	}

	if(W != 2*B) {
		cout<<"NO"<<endl;
		return 0;
	}

	const int UP=0, LEFT=1, DOWN=2, RIGHT=3;
	vector<vector<vi>> edge(N, vector<vi>(M, vi(4, -1)));
	int c = 0;
	for(int i=0; i<N; ++i) {
		for(int j=0; j<M; ++j) {
			if(bounds(i-1, j)) {
				edge[i][j][UP] = edge[i-1][j][DOWN];
			}
			if(bounds(i, j-1)) {
				edge[i][j][LEFT] = edge[i][j-1][RIGHT];
			}
			if(i < N-1) edge[i][j][DOWN] = c++;
			if(j < M-1) edge[i][j][RIGHT] = c++;
		}
	}

	G.clear();
	G.numNodes = N * M * 4;

	vector<vector<bool>> forced(N, vector<bool>(M, 0));
	for(auto [y,x]:b) {
		bool up = bounds(y-1, x) && !forced[y-1][x] && V[y-1][x] == 'W';
		bool left = bounds(y, x-1) && !forced[y][x-1] && V[y][x-1] == 'W';
		bool down = bounds(y+1, x) && !forced[y+1][x] && V[y+1][x] == 'W';
		bool right = bounds(y, x+1) && !forced[y][x+1] && V[y][x+1] == 'W';

		if((!up && !down) || (!left && !right)) {
			cout<<"NO"<<endl;
			return 0;
		}

		int eUP = edge[y][x][UP];
		int eLEFT = edge[y][x][LEFT];
		int eDOWN = edge[y][x][DOWN];
		int eRIGHT = edge[y][x][RIGHT];

		if(up && !down) {
			add_clause(G, VAR(eUP), VAR(eUP));
			forced[y-1][x] = 1;
		}
		else if(!up && down) {
			add_clause(G, VAR(eDOWN), VAR(eDOWN));
			forced[y+1][x] = 1;
		}
		else {
			add_clause(G, VAR(eUP), VAR(eDOWN));
			add_clause(G, NOT(VAR(eUP)), NOT(VAR(eDOWN)));
		}

		if(left && !right) {
			add_clause(G, VAR(eLEFT), VAR(eLEFT));
			forced[y][x-1] = 1;
		}
		else if(!left && right) {
			add_clause(G, VAR(eRIGHT), VAR(eRIGHT));
			forced[y][x+1] = 1;
		}
		else {
			add_clause(G, VAR(eLEFT), VAR(eRIGHT));
			add_clause(G, NOT(VAR(eLEFT)), NOT(VAR(eRIGHT)));
		}
	}

	for(auto [y,x]:w) {
		bool up = bounds(y-1, x) && V[y-1][x] == 'B';
		bool left = bounds(y, x-1) && V[y][x-1] == 'B';
		bool down = bounds(y+1, x) && V[y+1][x] == 'B';
		bool right = bounds(y, x+1) && V[y][x+1] == 'B';

		if(!up && !left && !down && !right) {
			cout<<"NO"<<endl;
			return 0;
		}
		
		int eUP = edge[y][x][UP];
		int eLEFT = edge[y][x][LEFT];
		int eDOWN = edge[y][x][DOWN];
		int eRIGHT = edge[y][x][RIGHT];
		
		vi temp;
		if(up) temp.push_back(eUP);
		if(left) temp.push_back(eLEFT);
		if(right) temp.push_back(eRIGHT);
		if(down) temp.push_back(eDOWN);

		for(int i=0; i<sz(temp); ++i) {
			for(int j=i+1; j<sz(temp); ++j) {
				add_clause(G, NOT(VAR(temp[i])), NOT(VAR(temp[j])));
			}
		}
	}

	bool val[MAX_VARS];
	if(twoSAT(G, val))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
