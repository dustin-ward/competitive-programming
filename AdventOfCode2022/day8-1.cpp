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

int main() {
	vector<string> G;
	string s;
	while(getline(cin,s)) {
		G.push_back(s);
	}

	vector<vi> V(sz(G), vi(sz(G[0]), 0));

	for(int i=0; i<sz(G); ++i) {
		int lastTree = -1;
		for(int j=0; j<sz(G[0]); ++j) {
			if(G[i][j]-'0' > lastTree) {
				V[i][j] = 1;
				lastTree = G[i][j]-'0';
			}
		}
	}
	for(int i=0; i<sz(G); ++i) {
		int lastTree = -1;
		for(int j=sz(G[0])-1; j>=0; --j) {
			if(G[i][j]-'0' > lastTree) {
				V[i][j] = 1;
				lastTree = G[i][j]-'0';
			}
		}
	}
	for(int i=0; i<sz(G[0]); ++i) {
		int lastTree = -1;
		for(int j=0; j<sz(G); ++j) {
			if(G[j][i]-'0' > lastTree) {
				V[j][i] = 1;
				lastTree = G[j][i]-'0';
			}
		}
	}
	for(int i=0; i<sz(G[0]); ++i) {
		int lastTree = -1;
		for(int j=sz(G)-1; j>=0; --j) {
			if(G[j][i]-'0' > lastTree) {
				V[j][i] = 1;
				lastTree = G[j][i]-'0';
			}
		}
	}

	int ans = 0;
	for(auto v:V)
		for(auto i:v)
			ans += i;
	cout<<ans<<endl;
}
