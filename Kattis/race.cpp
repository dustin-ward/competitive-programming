#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define sz(x) (int)(x).size()
#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.first << ", " << x.second << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

struct Node {
    int p;
    int t;
    int d;
};

int N,T;
vector<Node> D(30);
vector<vi> G(30, vi(30));
int dp[1<<20][22];

int startNode, endNode;

int f(int S, int nd) {
    // debug(S);
    // debug(nd);
    if(S & (1<<nd)) {
        int t = f(S & ~(1<<nd), nd);
        if(t <= D[nd].d-D[nd].t)
            return t + D[nd].t;
        else
            return 1<<20;
    }

    if(!S)
        return G[startNode][nd];
    if(dp[S][nd] != -1)
        return dp[S][nd];

    int ans = 1<<20;
    for(int i=0; i<N; ++i) {
        if(S & (1<<i))
            ans = min(ans, f(S, i) + G[i][nd]);
    }
    return dp[S][nd] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N>>T;
    // D.resize(N);
    // G.resize(N+2, vi(N+2));
    startNode = N;
    endNode = N+1;

    for(int i=0; i<1<<20; ++i)
        for(int j=0; j<22; ++j)
            dp[i][j] = -1;

    for(int i=0; i<N; ++i) {
        cin>>D[i].p>>D[i].t>>D[i].d;
        D[i].d = (D[i].d >= 0) ? D[i].d : T+1;
    }
    
    for(int i=0; i<N+2; ++i)
        for(int j=0; j<N+2; ++j)
            cin>>G[i][j];

    int ans = 0;
    vi path;
    for(int S=0; S<(1<<N); ++S) {
        if(f(S, endNode) <= T) {
            int score = 0;
            vi tempPath;
            for(int i=0; i<N; ++i) {
                if(S & (1<<i)) {
                    tempPath.push_back(i+1);
                    score += D[i].p;
                }
            }
            if(score > ans) {
                ans = score;
                path = tempPath;
            }
            else if(score == ans && tempPath < path) {
                path = tempPath;
            }
        }
    }

    cout<<ans<<endl;
    for(int i=0; i<path.size(); ++i)
        printf("%d%c", path[i], (i==path.size()-1) ? '\n' : ' ');
}