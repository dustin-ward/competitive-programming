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

const int ROW = 2000000;

int main() {
    string ln;
    vpii S,B;
    while(getline(cin,ln)) {
        istringstream iss(ln);
        string g;
        char c;
        pii s,b;
        iss>>g>>g>>c>>c>>s.snd>>c>>c>>c>>s.fst;
        assert(g == "at");
        assert(c == '=');
        iss>>c>>g>>g>>g>>g>>c>>c>>b.snd>>c>>c>>c>>b.fst;
        assert(g == "at");
        assert(c == '=');
        S.push_back(s);
        B.push_back(b);
    }

    vpii R;
    for(int i=0; i<sz(S); ++i) {
        pii s = S[i];
        pii b = B[i];

        int dis = abs(s.fst-b.fst)+abs(s.snd-b.snd);
        int vDis = abs(s.fst-ROW);

        if(dis >= vDis) {
            int hDis = dis-vDis;
            R.emplace_back(s.snd-hDis, s.snd+hDis);
        }
    }

    sort(all(R));

    int ans = abs(R[0].snd-R[0].fst)+1;
    int last = R[0].snd;
    for(int i=1; i<sz(R); ++i) {
        if(R[i].snd <= last) continue;
        if(R[i].fst <= last) ans -= abs(R[i].fst-last)+1;
        ans += abs(R[i].snd-R[i].fst)+1;
        last = R[i].snd;
    }

    set<pii> overlap;
    for(pii b:B)
        if(b.fst == ROW) overlap.insert(b);
    for(pii s:S)
        if(s.fst == ROW) overlap.insert(s);
    ans -= sz(overlap);

    cout<<ans<<endl;
}
