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

ll win(ll x, ll y) {
    return max(x, (3*y + x)/2);
}
ll lose(ll x, ll y) {
    return min(y, (ll)((x/3.0 + y)/2.0));
}

ll scale(ll z, ll a, ll b) {
    bool neg = z<0;
    ll tmp = (b+1)*abs(z)/(a+b+2);
    return neg?-tmp:tmp;
}

ll cap(ll z) {
    if(z>1000) z = 1000;
    if(z<-1000) z = -1000;
    return z;
}

int main() {
    int N,M; cin>>N>>M;
    vector<pair<ll,ll>> W(N);

    ll nw = 1500;
    while(M--) {
        int u,v; cin>>u>>v;
        u--; v--;
        pair<ll,ll> &U = W[u];
        pair<ll,ll> &V = W[v];
        bool un=0,vn=0;
        if(!U.snd) {
            U.fst = nw;
            un = 1;
        }
        if(!V.snd) {
            V.fst = nw;
            vn = 1;
        }

        ll zu = win(U.fst, V.fst) - U.fst;
        /* debug(U.fst+zu); */
        zu = scale(zu, U.snd, V.snd);
        /* debug(zu); */
        zu = cap(zu);
        
        ll zv = lose(U.fst, V.fst) - V.fst;
        /* debug(V.fst+zv); */
        zv = scale(zv, V.snd, U.snd);
        /* debug(zv); */
        zv = cap(zv);
        
        U.fst += zu;
        V.fst += zv;
        U.snd++;
        V.snd++;
    
        // New new Ratings
        if(un && !vn)
            nw = U.fst;
        if(!un && vn)
            nw = V.fst;

        cout<<U.fst<<" "<<V.fst<<endl;
    }
}
