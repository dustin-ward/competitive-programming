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

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};

int R,C;
vector<string> B;
vector<vi> V;

bool bounds(int i, int j) {
    return i>=0 && i < R && j >= 0 && j < C;
}

int si,sj;
int f(int i, int j) {
    /* cout<<"at "<<i<<" "<<j<<endl; */
    V[i][j] = 1;

    int ans = 1;
    bool bad = false;
    for(int k=0; k<4; k++) {
        int i2 = i+dy[k];
        int j2 = j+dx[k];
        if(bounds(i2,j2) && !V[i2][j2]) {
            if(B[i2][j2] == '.' && !(i2 == si && j2 == sj))
                bad = 1;
            if(B[i2][j2] == 'W') {
                int x = f(i2,j2);
                if(x == -1)
                    bad = 1;
                else
                    ans += x;
            }
        }
    }
    /* debug(ans); */
    /* debug(bad); */
    return bad?-1:ans;
}

int main() {
    int T, caseno=1; cin>>T;
    while(T--) {
        cin>>R>>C;
        B.clear();
        B.resize(R,string(C,0));
        V.clear();
        V.resize(R,vi(C,0));
        for(int i=0; i<R; i++)
            cin>>B[i];
        /* debug(B); */
        
        cout<<"Case #"<<caseno++<<": ";
        int ans = 0;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(B[i][j] != '.') continue;
                si = i;
                sj = j;
                /* debug(i); */
                /* debug(j); */
                int temp=0;
                for(int k=0; k<4; k++) {
                    int i2 = i+dy[k];
                    int j2 = j+dx[k];
                    if(bounds(i2,j2) && B[i2][j2] == 'W' && !V[i2][j2]) {
                        int x = f(i2,j2);
                        /* debug(i2); */
                        /* debug(j2); */
                        /* debug(x); */
                        if(x != -1) {
                            temp += x;
                            /* debug(temp); */
                        }
                    }
                    ans = max(ans, temp);
                }
            }
        }
        /* debug(V); */
        cout<<ans<<endl;
    }
}
