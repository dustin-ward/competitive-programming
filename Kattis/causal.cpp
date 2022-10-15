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

const int OFF = 2000000;

struct Event {
	int t;
	int x;
};

int N,M;
vector<Event> E;

bool canCause(const Event &e1, const Event &e2) {
	return e2.t >= e1.t + abs(e2.x - e1.x);
}

bool check(int T) {
	Event c;
	c.t = T;
	c.x = (E[0].t+E[0].x) - T;

	int count = 1;
	for(int i=0; i<N; ++i) {
		if(!canCause(c, E[i])) {
			count++;
			if(count > M)
				return false;
			c.x = (E[i].t+E[i].x) - T;
		}
	}
	return true;
}

int main() {
	int T,caseno=1; cin>>T;
	while(T--) {
		cin>>N>>M;
		int minT = INT_MAX;
		E.resize(N);
		for(int i=0; i<N; ++i) {
			int t,x; cin>>t>>x;
			E[i] = {t+OFF,x};
			minT = min(minT,t+OFF);
		}

		sort(E.begin(), E.end(), [](const Event &a, const Event &b) {
			return a.t+a.x < b.t+b.x;
		});
		
		cout<<"Case "<<caseno++<<": ";

		int lo=0, hi=minT;
		if(check(hi)) {
			cout<<hi-OFF<<endl;
			continue;
		}

		while(abs(hi-lo)>1) {
			int mid = (lo+hi)/2;
			if(check(mid))
				lo = mid;
			else
				hi = mid;
//			debug(lo-OFF);
//			debug(mid-OFF);
//			debug(hi-OFF);
		}
		cout<<lo-OFF<<endl;
	}
}
