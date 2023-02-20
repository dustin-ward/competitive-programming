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

int dx[6] = {-1,0,1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

bool bounds(int x, int y, int z) {
    return x >= 0 && y >= 0 && z >= 0 && x < 25 && y < 25 && z < 25;
}

vector<vector<vi>> G(25, vector<vi>(25, vi(25,0)));
vector<vector<vi>> V(25, vector<vi>(25, vi(25,0)));
void dfs(int x, int y, int z) {
    V[x][y][z] = 1;
    for(int k=0; k<6; ++k) {
        int x2 = x+dx[k];
        int y2 = y+dy[k];
        int z2 = z+dz[k];
        if(bounds(x2,y2,z2)&&!G[x2][y2][z2]&&!V[x2][y2][z2])
            dfs(x2,y2,z2);
    }
}

int main() {
    int x,y,z;
    char c;
    while(cin>>x>>c>>y>>c>>z) 
        G[x+1][y+1][z+1] = 1;

    dfs(0,0,0);

    int ans = 0;
    for(int i=0; i<25; ++i) {
        for(int j=0; j<25; ++j) {
            for(int k=0; k<25; ++k) {
                if(!G[i][j][k]) continue;
                for(int d=0; d<6; ++d) {
                    int x2 = i+dx[d];
                    int y2 = j+dy[d];
                    int z2 = k+dz[d];
                    if(bounds(x2,y2,z2)&&!G[x2][y2][z2]&&V[x2][y2][z2])
                        ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
