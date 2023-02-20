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

map<string,int> L;

vector<vi> G;

int N,M;
vi D,C;

int main() {
    cin>>N>>M;
    D.resize(N+1, -1);
    C.resize(N+1, -1);
    G.resize(N+1, vi(N+1,-1));

    L["English"] = 0;
    for(int i=1; i<=N; ++i) {
        string s; cin>>s;
        L[s] = i;
    }

    for(int i=0; i<M; ++i) {
        string u,v; cin>>u>>v;
        int c; cin>>c;
        G[L[u]][L[v]] = G[L[v]][L[u]] = c;
    }

    queue<int> Q;
    Q.push(0);
    D[0] = 0;
    C[0] = 0;
    while(!Q.empty()) {
        int n = Q.front(); Q.pop();

        for(int i=0; i<=N; ++i) {
            if(G[n][i] == -1) continue;
            if(D[i] == -1) {
                D[i] = D[n]+1;
                C[i] = G[n][i];
                Q.push(i);
            }
            else if(D[i] == D[n]+1)
                C[i] = min(C[i], G[n][i]);
        }
    }

    debug(D);
    debug(C);

    int ans = 0;
    bool good = true;
    for(int i=0; i<=N; ++i) {
        if(C[i] == -1)
            good = false;
        ans += C[i];
    }
    if(good)
        cout<<ans<<endl;
    else
        cout<<"Impossible"<<endl;
}
