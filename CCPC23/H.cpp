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

int N,F;
vector<vi> B;

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

bool bounds(int i, int j) {
    return i>=0 && i<N && j>=0 && j<N;
}

int DP[21][21][401];

vector<vi> V;
int dfs(int i, int j, int f) {
    int &ans = DP[i][j][f];
    if(ans != -1) return ans;
    // debug(make_pair(i,j));
    ans = B[i][j];
    V[i][j] = 1;

    if(f) {
        int temp = 0;
        for(int k=0; k<4; k++) {
            int i2 = i+dy[k];
            int j2 = j+dx[k];
            if(bounds(i2,j2) && !V[i2][j2] && B[i2][j2] > B[i][j]) {
                temp = max(temp, dfs(i2,j2,f-1));
            }
        }
        ans += temp;
    }
    // debug(ans);
    V[i][j] = 0;
    return ans;
}

int main() {
    for(int i=0; i<21; i++)
        for(int j=0; j<21; j++)
            for(int k=0; k<401; k++)
                DP[i][j][k] = -1;

    cin>>N>>F;
    B.resize(N,vi(N));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>B[i][j];

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j+=(i==0||i==N-1)?1:N-1) {
            V.clear();
            V.resize(N,vi(N,0));
            // debug("NEW DFS");
            ans = max(ans, dfs(i,j,F));
        }
    }
    cout<<ans<<endl;
}
