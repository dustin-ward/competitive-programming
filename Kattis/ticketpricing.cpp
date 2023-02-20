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

int dp[101][301][53];
int N,W;
vector<vpii> K;

int f(int p, int n, int w) {
    // cout<<"====="<<endl;
    // debug(p);debug(n);debug(w);
    int &ans = dp[p][n][w];
    if(ans != -1) return ans;

    int sold = min(n,K[w][p].snd);
    ans = sold * K[w][p].fst;

    if(w < W) {
        int ans2 = 0;
        for(int i=0; i<sz(K[w+1]); i++)
            ans2 = max(ans2,f(i,n-sold,w+1));
        ans += ans2;
    }
    
    // debug(ans);
    return ans;
}

int main() {
    cin>>N>>W;
    K.resize(W+1);

    for(int i=0; i<101; i++)
        for(int j=0; j<=N; j++)
            for(int k=0; k<=W; k++)
                dp[i][j][k] = -1;

    for(int i=0; i<=W; i++) {
        int k; cin>>k;
        K[i].resize(k);
        for(int j=0; j<k; j++)
            cin>>K[i][j].fst;
        for(int j=0; j<k; j++)
            cin>>K[i][j].snd;
    }

    int ans = 0;
    int p=K[0][0].fst;
    for(int i=0; i<sz(K[0]); i++) {
        int r = f(i,N,0);
        if(r > ans) {
            ans = r;
            p = K[0][i].fst;
        }
        else if(r == ans) {
            p = min(p, K[0][i].fst);
        }
    }
    cout<<ans<<"\n"<<p<<endl;
}
