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

struct Shield {
    int l;
    int u;
    double f;

    bool operator<(const Shield &s) {
        return l < s.l;
    }
};

int X,Y,N;
vector<Shield> S;
bool negative = false;

bool f(double h) {
    double hPos = 0.0;
    double vPos = 0.0;

    for(Shield &s:S) {
        // Get to bottom of shield
        double dy = s.l - vPos;
        hPos += dy * h;
        vPos = s.l;

        // Go through shield;
        dy = s.u - s.l;
        hPos += dy * s.f * h;
        vPos = s.u;
    }

    // Get to ship
    double dy = Y - vPos;
    hPos += dy * h;

    return hPos > X;
}

int main() {
    cin>>X>>Y>>N;
    if(X<0) {
        negative = 1;
        X = -X;
    }

    S.resize(N);
    for(Shield &s:S)
        cin>>s.l>>s.u>>s.f;

    sort(all(S));

    double upperBound = 1.0;
    while(!f(upperBound)) upperBound *= 2;

    double lo=0.0, hi=upperBound;
    while((hi-lo)>0.000000001) {
        double mid = (lo+hi)/2;
        if(f(mid))
            hi = mid;
        else
            lo = mid;
    }
    
    cout<<fixed<<setprecision(10)<<(negative?-lo:lo)<<endl;
}
