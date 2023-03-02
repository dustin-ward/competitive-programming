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

int N,X;

struct Point {
    int inptIdx;
    int originIdx;
    ll x;
    ll y;
    ll v;
 
    // Compare points by angle around origin
    bool operator<(const Point &b) {
        return x*b.y > y*b.x;
    }
};

// Segment Tree from KTH
// Default value set to 0
// Op set to a+b
vector<Point> P;
struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
    cin>>N>>X;
    P.resize(N);
    for(int i=0; i<N; i++) {
        Point &p = P[i];
        cin>>p.x>>p.y>>p.v;
        p.inptIdx=i;
    }

    // Sort points CW around point (X,0)
    sort(rall(P), [](Point a, Point b){
        a.x -= X;
        b.x -= X;
        return a<b;
    });

    // Keep indices on the sorted order CW around the origin
    vi idx(N);
    for(int i=0; i<N; i++)
        idx[i] = i;
    sort(rall(idx), [](const int &a, const int &b){return P[a] < P[b];});
    for(int i=0; i<N; i++)
        P[idx[i]].originIdx=i;

    // Keep segment tree on origin indices previously calculated.
    // SegTree.query(a,b) is the total weight of all points encountered so far
    // between idx(a) and idx(b) in the orign-order
    Tree segTree(N);

    // In order of P (CW around (X,0)) ans for this point is the segtree query
    // from this point to N. This only counts points that have been part of the
    // triangle so far. Update idx in segment tree after calculating answer.
    vector<ll> ans(N);
    for(int i=0; i<N; i++) {
        ans[P[i].inptIdx] += segTree.query(P[i].originIdx,N); 
        segTree.update(P[i].originIdx, P[i].v);
    }
    for(ll &i:ans)
        cout<<i<<endl;
}
