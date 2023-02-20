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

int N,M,ans = INT_MAX,value;

struct Node {
    int Items;
    int Distance = INT_MAX;
    bool Visited = false;
    vpii Edges;
};
vector<Node> G;

void dfs(int n) {
    if(n == N-1) {
        if(G[n].Distance < ans) {
            ans = G[n].Distance;
            value = G[n].Items;
        }
        else if(G[n].Distance == ans)
            value = max(value, G[n].Items);
        return;
    }

    for(auto &[v,w]:G[n].Edges) {
        if(!G[v].Visited && G[n].Distance+w <= G[v].Distance) {
            G[v].Distance = G[n].Distance+w;
            G[v].Items += G[n].Items;
            G[v].Visited = 1;
            dfs(v);
            G[v].Visited = 0;
            G[v].Items -= G[n].Items;
        }
    }
}

int main() {
    cin>>N;
    G.resize(N);
    for(Node &n:G)
        cin>>n.Items;

    cin>>M;
    for(int i=0; i<M; ++i) {
        int u,v,w; cin>>u>>v>>w;
        u--; v--;
        G[u].Edges.emplace_back(v,w);
        G[v].Edges.emplace_back(u,w);
    }

    G[0].Visited = 1;
    G[0].Distance = 0;
    dfs(0);

    if(G[N-1].Distance == INT_MAX)
        cout<<"impossible"<<endl;
    else
        cout<<ans<<" "<<value<<endl;
}
