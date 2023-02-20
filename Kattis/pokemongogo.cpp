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

int N,P;
int ans = INT_MAX;
vi T;
vector<vi> G;

map<string,int> M;
int getId(string s) {
    if(!M.count(s))
        M[s] = sz(M);
    return M[s];
}

void f(int n, int d, int m) {
    debug(n);debug(d);debug(m);
    cout<<(1<<P)-1<<" == "<<m<<"?"<<endl;
    if(m == ((1<<P)-1)) {
        ans = min(ans, d);
        return;
    }

    for(int i=0; i<N; ++i) {
        if(G[n][i] == -1) continue;
        if(m & (1<<T[i])) continue;
        f(i, d+G[n][i], m | (1<<T[i]));
    }
}

int main() {
    cin>>N;

    N++;
    vector<pii> V(N);
    T.resize(N);
    V[0] = {0,0};
    for(int i=1; i<N; ++i) {
        cin>>V[i].fst>>V[i].snd;
        string s; cin>>s;
        T[i] = getId(s);
    }
    T[0] = sz(M);

    P = sz(M);
    G.resize(N, vi(N, -1));
    for(int i=0; i<N; ++i) {
        for(int j=i+1; j<N; ++j) {
            int dy = abs(V[i].snd-V[j].snd);
            int dx = abs(V[i].fst-V[j].fst);
            G[i][j] = G[j][i] = dy + dx;
        }
    }

    f(0,0,(1<<T[0]));

    cout<<ans<<endl;
}
