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

int N;
vi P;
double dp[101][101][101];

double f(int b0, int b1, int b2, int tot, int cur) {
    if(b0 < 0 || b1 < 0 || b2 < 0) return 0.0;

    if(dp[b0][b1][b2] >= 0)
        return dp[b0][b1][b2];

    double ans = cur;
    if(tot >= 3*N || (!b0 && !b1 && !b2))
        return dp[b0][b1][b2] = ans;

    cur += P[tot];
    double ans2 = 0.0;
    ans2 += (double)b0/N * f(b0-1, b1+1, b2, tot+1, cur);
    ans2 += (double)b1/N * f(b0, b1-1, b2+1, tot+1, cur);
    ans2 += (double)b2/N * f(b0, b1, b2-1, tot+1, cur);

    return dp[b0][b1][b2] = max(ans, ans2);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N;
    P.resize(3*N);
    for(int &i:P)
        cin>>i;
    
    debug(P);

    for(int i=0; i<=N; i++) {
        for(int j=0; j<=N; j++) {
            for(int k=0; k<=N; k++)
                dp[i][j][k] = -1.0;
        }
    }

    cout<<fixed<<setprecision(16)<<f(N,0,0,0,0)<<endl;
}