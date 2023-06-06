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
// double curTime() { return double(clock()) / CLOCKS_PER_SEC; }

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

int t,q;
int curTime;
string s[3];

unordered_map<int,int> B;
bool blocked(int i) {
	if(B.count(i) && curTime < B[i]+t) {
		return true;
	}
	return false;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>s[1]>>s[2];
		cin>>t>>q;
		int N = sz(s[1]);
		B.clear();
		curTime = 0;

		bool cached = false;
		bool cacheval = false;
		priority_queue<int> pq;
		while(q--) {
			// debug(curTime);
			// if(!pq.empty()) debug(pq.top());
			// debug(cached);
			if(!pq.empty() && (-pq.top())+t <= curTime) {
				// debug("popping");
				pq.pop();
				cached = 0;
			}
	
			int op; cin>>op;
			if(op == 1) {
				int pos; cin>>pos;
				B[pos] = curTime;
				pq.push(-curTime);
				cached = 0;
			} else if(op == 2) {
				int x1,p1,x2,p2; cin>>x1>>p1>>x2>>p2;
				swap(s[x1][p1-1], s[x2][p2-1]);
				if(s[x1][p1-1] != s[x2][p2-1])
					cached = 0;
			} else {
				if(!cached) {
					bool same = 1;
					for(int i=0; i<N; i++) {
					if(blocked(i+1)) continue;
						if(s[1][i] != s[2][i]) {
							same = 0;
							break;
						}
					}
					cacheval = same;
					cached = 1;
				}
				cout<<(cacheval?"YES":"NO")<<endl;
			}
			curTime++;
		}
	}
}
