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

struct Vlv {
    int val;
    vi tunnels;
};

map<string,int> M;
int getId(string s) {
    if(!M.count(s))
        M[s] = sz(M);
    return M[s];
}

vector<Vlv> G;
map<ll,int> DP[100][31];
int maxPressure(int n, int t, ll m) {
    map<ll,int> &M = DP[n][t];
    if(M.count(m))
        return M[m];

    if(t <= 0) return 0;
    int ans = 0;
    int open = G[n].val * (t-1);

    if(G[n].val && (m & (1LL<<n)) == 0)
        ans = max(ans, maxPressure(n, t-1, m | (1LL<<n)) + open);

    for(int i:G[n].tunnels) {
        int dontOpen = maxPressure(i,t-1,m);
        ans = max(ans, dontOpen);
    }

    return M[m] = ans;
}

int main() { 
    G.resize(100);
    string s;
    while(getline(cin,s)) {
        s += ",";
        istringstream iss(s);
        string g,lbl;
        char c;
        
        Vlv v;
        iss>>g>>lbl>>g>>g>>c>>c>>c>>c>>c>>v.val>>c>>g>>g>>g>>g;
        assert(g == "valves" || g == "valve");
        int id = getId(lbl);

        string lbl2;
        while(iss>>lbl2) {
            lbl2 = lbl2.substr(0, sz(lbl2)-1);
            v.tunnels.push_back(getId(lbl2));
        }
        G[id] = v;
    }

    cout<<maxPressure(getId("AA"), 30, 0)<<endl;
}
