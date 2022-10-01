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

int N;
vi A;
vector<vi> G;
set<pii> S;

void DFS(int n, vi reached, vi &visited, vi &visited2) {
	if(n >= N) return;
	if(visited2[n]) return;
	visited[n] = 1;
	visited2[n] = 1;

	reached.push_back(n);
	for(int i:reached)
		S.insert(make_pair(i,A[n]));

	for(int i:G[n])
		DFS(i, reached, visited, visited2);
}

int main() {
	cin>>N;
	A.resize(N);
	G.resize(N+1);
	for(int i=0; i<N; ++i) {
		cin>>A[i];
		int v;
		if(A[i] < 0)
			v = i - (N-abs(A[i]));
		else
			v = i + (N-A[i]);
		debug(v);
		if(v < 0 || v >= N)
			G[i].push_back(N);
		else
			G[i].push_back(v);
	}

	int ans = 0;
	int idx = 0;
	vi reached, visited(N,0);
	while(idx < N) {
		//if(!visited[idx]) { 
		if(sz(G[idx]) <= 1) {
			vi visited2(N,0);
			DFS(idx, reached, visited, visited2);
		}
		++idx;
	}
	debug(G);
	debug(S);
	cout<<S.size()<<endl;
}
