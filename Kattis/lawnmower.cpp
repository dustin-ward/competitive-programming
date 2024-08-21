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

double E = 1e-9;

bool feq(double a, double b) {
	return fabs(a-b) < E;
}

int main() {
	int nx,ny;
	double w;
	while(cin>>nx>>ny>>w && !(nx==0&&ny==0&&feq(w,0.0))) {
		list<pair<double,double>> horizontal, vertical;
		for (int i=0; i<nx; i++) {
			double x; cin>>x;
			vertical.emplace_back(max(0.0, x-(w/2)), min(75.0, x+(w/2)));
		}
		for (int i=0; i<ny; i++) {
			double x; cin>>x;
			horizontal.emplace_back(max(0.0, x-(w/2)), min(100.0, x+(w/2)));
		}
		horizontal.sort();
		vertical.sort();

		double pos = 0.0;
		bool valid = true;
		while (!vertical.empty() && !feq(pos, 75.0)) {
			auto cur = vertical.front();
			vertical.pop_front();

			if (cur.fst > pos) {
				valid = false;
				break;
			}

			pos = cur.snd;
		}
		if (!feq(pos,75.0)) valid = false;

		pos = 0.0;
		while (!horizontal.empty() && !feq(pos, 100.0)) {
			auto cur = horizontal.front();
			horizontal.pop_front();

			if (cur.fst > pos) {
				valid = false;
				break;
			}

			pos = cur.snd;
		}
		if (!feq(pos,100.0)) valid = false;

		cout<<(valid ? "YES" : "NO")<<endl;
	}
}
