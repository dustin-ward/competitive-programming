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

int N,M;
vector<vector<ll>> B;

bool bounds(int i, int j) {
    return i>=0 && i<N && j>=0 && j<M;
}

int dx[3] = {0,-1,-1};
int dy[3] = {-1,-1,0};
int p[3] = {10,15,10};

ll DP[1001][1001];
ll f(int i, int j) {
    ll &ans = DP[i][j];
    if(ans != -2) return ans;

    ans = -1;
    for(int k=0; k<3; k++) {
        int i2 = i+dy[k];
        int j2 = j+dx[k];

        if (bounds(i2,j2)) {
            ll speed = (B[i2][j2]-B[i][j])-p[k];
            ll fans = f(i2,j2);
            if(fans == -1 || fans+speed<0) continue;
            ans = max(ans, fans+speed);
        }
    }

    return ans;
}

int main() {
    cin>>N>>M;
    B.resize(N, vector<ll>(M));
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>B[i][j];
            DP[i][j] = -2;
        }
    }
    DP[0][0] = 0;

    ll ans = f(N-1,M-1);
    cout<<(ans == -1 ? "TOO SLOW" : to_string(ans))<<endl;

    /* for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    } */
}
