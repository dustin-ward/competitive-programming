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

const int MOD = 1000000007;

ll dp[2001][2001];
string s;

ll f(int start, int end) {
    if(end - start == 1)
        return 1;
    if(end - start == 0)
        return 0;
    if(dp[start][end] >= 0)
        return dp[start][end];
    
    dp[start][end] = 0;
    if(s[start] == s[end-1])
        dp[start][end] = (dp[start][end] + f(start+1, end-1) + 1) % MOD;

    dp[start][end] = (dp[start][end] + f(start+1, end)) % MOD;
    dp[start][end] = (dp[start][end] + f(start, end-1)) % MOD;
    dp[start][end] = (dp[start][end] + (MOD - f(start+1, end-1))) % MOD;
    return dp[start][end];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        for(int i=0; i<=2000; i++) {
            for(int j=0; j<=2000; j++)
                dp[i][j] = -1;
        }
        cin>>s;
        cout<<f(0, s.length())<<endl;
    }
}