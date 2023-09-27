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

int V,E;
vector<vi> G;
vi DIS,VIS,PATH;

void dfs(int n) {
	debug(n);
	assert(n>=0 && n < sz(VIS));
	VIS[n] = 1;
	for(int i:G[n]) {
		debug(i);
		assert(i>=0 && i < sz(VIS));
		if(!VIS[i])
			dfs(i);

		assert(i>=0 && i < sz(DIS));
		assert(n>=0 && n < sz(DIS));
		if(1 + DIS[i] > DIS[n]) {
			DIS[n] = 1 + DIS[i];
			assert(n>=0 && n < sz(PATH));
			PATH[n] = i;
		}
	}
}

int main() {
	cin>>V>>E;
	DIS.resize(V,0);
	VIS.resize(V,0);
	PATH.resize(V,-1);
	G.resize(V);
	cout<<"TEST1"<<endl;

	for(int i=0; i<E; i++) {
		int u,v; cin>>u>>v;
		u--; v--;
		G[u].push_back(v);
	}
	cout<<"TEST2"<<endl;

	for(int i=0; i<V; i++) {
		cout<<"TEST3 "<<i<<endl;
		assert(i>=0 && i < sz(VIS));
		if(VIS[i]) continue;
		dfs(i);
	}

	debug(DIS);
	debug(PATH);
	
	int maxIdx;
	int maxVal=0;
	for(int i=0; i<V; i++) {
		assert(i>=0 && i < sz(DIS));
		if(DIS[i]>maxVal) {
			maxIdx = i;
			maxVal = DIS[i];
		}
	}

	cout<<maxVal+1<<endl;

	while(maxIdx != -1) {
		cout<<maxIdx+1<<" ";
		maxIdx = PATH[maxIdx];
	}

	// reverse(begin(path), end(path));
	// for(int i:path)
	// 	cout<<i+1<<" ";
	cout<<endl;
}
