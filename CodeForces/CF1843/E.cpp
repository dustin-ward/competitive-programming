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

int N,M,Q;
vpii P;
vi X;

bool f(int m) {
	vi A(N,0);
	for(int i=0; i<m; i++)
		A[X[i]] = 1;
	vi ps(N+1,0);
	for(int i=0; i<N; i++)
		ps[i+1] = ps[i] + A[i];

	for(auto &[l,r]:P) {
		if(ps[r]-ps[l] > (r-l)/2)
			return true;
	}
	return false;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>N>>M;
		P.clear();
		for(int i=0; i<M; i++) {
			int l,r; cin>>l>>r;
			P.emplace_back(l-1,r);
		}

		cin>>Q;
		X.clear();
		X.resize(Q);
		for(int &i:X) {
			cin>>i;
			i--;
		}

		int lo=0, hi=Q+1;
		while(hi-lo > 1) {
			int mid = (lo+hi)/2;
			if(f(mid)) {
				// debug("T")
				hi = mid;
			} else {
				// debug("F")
				lo = mid;
			}
		}
		if(hi==Q+1)
			cout<<-1<<endl;
		else
			cout<<hi<<endl;
	}
}
