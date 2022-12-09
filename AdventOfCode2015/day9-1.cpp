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

map<string,int> M;
int getId(string s) {
	if(!M.count(s))
		M[s] = sz(M);
	return M[s];
}

struct Edge {
	int u;
	int v;
	int w;
};

vector<vi> G;

vi visited;
int dfs(int n, int d) {
	if(d == sz(M))
		return 0;
//	debug(n);
	int sans = INT_MAX;
	for(int i=0; i<sz(G[n]); ++i) {
		if(G[n][i] != -1 && !visited[i]) {
			visited[i] = 1;
			int x = dfs(i,d+1);
			if(x != -1) sans = min(sans, G[n][i] + x);
			visited[i] = 0;
		}
	}
	if(sans == INT_MAX)
		return -1;
	return sans;
}

int main() {
	vector<string> S;
	string s;
	vector<Edge> E;
	while(getline(cin,s)) {
//		debug(s);
		istringstream iss(s);
		string u,v,g;
		int w;
		iss>>u>>g>>v>>g>>w;
		assert(g == "=");
		Edge e;
		e.u = getId(u);
		e.v = getId(v);
		e.w = w;
		E.push_back(e);
	}

	G.resize(sz(M), vi(sz(M), -1));
	visited.resize(sz(M), 0);
	for(Edge e:E) {
		G[e.u][e.v] = e.w;
		G[e.v][e.u] = e.w;
	}
//	debug(G);
	int ans = INT_MAX;
	for(int i=0; i<sz(M); ++i){
		visited[i] = 1;
		int x = dfs(i,1);
//		debug(x);
		if(x != -1) ans = min(ans, x);
		visited[i] = 0;
	}

	cout<<ans<<endl;
}
