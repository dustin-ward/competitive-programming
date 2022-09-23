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

int dp[2][20000];
int p3[9];
int b[9];

bool won(int p, int i, int j, int k) {
    return b[i] == p && b[j] == p && b[k] == p; 
}

void f(int board, int player) {
    if(dp[0][board] != -1)
        return;

    int p2 = 3-player;
    if( won(p2, 0, 1, 2) || won(p2, 3, 4, 5) || won(p2, 6, 7, 8) ||
        won(p2, 0, 3, 6) || won(p2, 1, 4, 7) || won(p2, 2, 5, 8) ||
        won(p2, 0, 4, 8) || won(p2, 2, 4, 6) ) {
            dp[p2-1][board] = 1;
            dp[player-1][board] = 0;
    }
    else {
        dp[0][board] = dp[1][board] = 0;
        for(int i=0; i<9; ++i) {
            if(!b[i]) {
                b[i] = player;
                int newBoard = board + (player*p3[i]);
                f(newBoard, p2);
                dp[0][board] += dp[0][newBoard];
                dp[1][board] += dp[1][newBoard];
                b[i] = 0;
            }
        }
    }
}

int main() {
    p3[0] = 1;
    for(int i=1; i<9; ++i)
        p3[i] = p3[i-1]*3;

    for(int i=0; i<9; ++i)
        b[i] = 0;

    for(int i=0; i<2; ++i)
        for(int j=0; j<20000; ++j)
            dp[i][j] = -1;

    f(0, 1);

    int T; cin>>T;
    for(int i=0; i<T; ++i) {
        string s; cin>>s;
        int k = 0;
        for(int i=0; i<9; ++i) {
            if(s[i] == 'X')
                k += 1*p3[i];
            else if(s[i] == 'O')
                k += 2*p3[i];
        }
        cout<<dp[0][k]<<" "<<dp[1][k]<<endl;
    }
}