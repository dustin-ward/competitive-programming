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

int main() {
	vector<vi> G(20, vi(20, 0));
	string s;
	while(getline(cin,s)) {
		istringstream iss(s);
		string name1,name2,gain,g;
		int val;
		iss>>name1>>g>>gain>>val>>g>>g>>g>>g>>g>>g>>name2;
		assert(g == "to");
		int p1 = getId(name1);
		int p2 = getId(name2.substr(0, sz(name2)-1));
		G[p1][p2] = (gain=="gain")? val : -val;
	}
	
	int ans = INT_MIN;
	vi c(sz(M)+1);
	for(int i=0; i<sz(M)+1; ++i)
		c[i] = i;

	do {
//		debug(c);
		int sum = 0;
		for(int i=0; i<sz(M)+1; ++i) {
			sum += G[c[i]][c[(i+1)%(sz(M)+1)]];
			sum += G[c[i]][c[(i+sz(M))%(sz(M)+1)]];
		}
//		debug(sum);
		ans = max(ans, sum);
	} while(next_permutation(all(c)));

	cout<<ans<<endl;
}
