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

int M,N;
ll dp[25][64];
int emptySpot[24];

ll f(int c, int b) {
    if(c >= M)
        return (!b) ? 1 : 0;

    if(dp[c][b] != -1)
        return dp[c][b];

    ll ans = 0;
    bool found = false;
    for(int i=0; i<3; ++i) {
        if(b & (1 << i))
            continue;
        if(emptySpot[c] & (1 << i))
            continue;
        
        ans += f(c, b | (1 << i));

        if(i<2 && !(b & (1 << (i+1))) && !(emptySpot[c] & (1 << (i+1))))
            ans += f(c, b | (3 << i));

        if(c<M-1 && !(b & (1 << (i+3))) && !(emptySpot[c+1] & (1 << i)))
            ans += f(c, b | (9 << i));

        found = true;
        break;
    }

    if(!found)
        return dp[c][b] = f(c+1, b >> 3);
    
    return dp[c][b] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>M>>N;
    for(int i=0; i<25; ++i)
        for(int j=0; j<64; ++j)
            dp[i][j] = -1;
        
    for(int i=0; i<24; ++i)
        emptySpot[i] = 0;

    for(int i=0; i<N; ++i) {
        double x,y; cin>>x>>y;
        emptySpot[(int)x] |= (1 << (int)y);
    }

    cout<<f(0, 0)<<endl;
}