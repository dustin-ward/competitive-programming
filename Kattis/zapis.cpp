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

const int MOD = 100000;
const string OPEN = "({[";
const string CLOSE = ")}]";
string S;
bool modded = false;

ll dp[201][201];

ll mod(ll x) {
    if(x >= MOD) {
        modded = true;
        return x % MOD;
    }
    return x;
}

ll f(int lo, int hi) {
    if(lo > hi) return 1;
    if(dp[lo][hi] != -1) return dp[lo][hi];

    ll ans = 0;
    for(int i=lo+1; i<=hi; i+=2) {
        for(int j=0; j<3; j++) {
            if(S[lo] == OPEN[j] || S[lo] == '?') {
                if(S[i] == CLOSE[j] || S[i] == '?')
                    ans = mod(ans + f(lo+1, i-1) * f(i+1,hi));
            }
        }
    }
    return dp[lo][hi] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin>>N;
    cin>>S;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            dp[i][j] = -1;
    }

    ll ans = f(0, N-1);
    if(modded)
        cout<<setw(5)<<setfill('0')<<ans<<endl;
    else
        cout<<ans<<endl;
}