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

int N;
vector<set<int>> G;
vi B;
vector<ll> V;
vi available;
vi order;

void maxTree(int n) {
    if(sz(G[n]) == 0) {
        if(!B[n]) available[n] = 0;
        return;
    }

    for(int i:G[n]) {
        maxTree(i);
    }

    int remove = 0;
    if(B[n] < sz(G[n]))
        remove = sz(G[n]) - B[n];

    int i=N-1;
    while(remove && i) {
        if(G[n].find(order[i])!=G[n].end()) {
            available[order[i]] = 0;
            remove--;
        }
        i--;
    }
}

int main() {
    cin>>N;
    G.resize(N);
    B.resize(N);
    V.resize(N);
    available.resize(N, 1);
    order.resize(N);
    for(int i=0; i<N; ++i)
        order[i] = i;

    for(int i=1; i<N; ++i) {
        int temp; cin>>temp;
        G[temp-1].insert(i);
    }
 
    for(int &i:B)
        cin>>i;
    for(ll &i:V)
        cin>>i;
    
    sort(all(order), [](const int& a, const int& b){return V[a] >= V[b];});
    maxTree(0);
    // debug(order);
    // debug(available);
    // debug(B);
    vi ansV;
    int i=0;
    while(sz(ansV) < B[0] && i<N) {
        if(available[order[i]])
            ansV.push_back(order[i]);
        i++;
    }
    sort(all(ansV));

    ll ans = 0;
    for(int &i:ansV)
        ans += V[i];
    cout<<ans<<endl<<sz(ansV)<<" ";
    for(int &i:ansV)
        cout<<i+1<<" ";
    cout<<endl;
}