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

struct Point {
    double x;
    double y;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    vector<vi> G(n);
    vector<Point> A(n), B(n);
    vector<bool> fix(n, 1);
    for(int i=0; i<n; i++) {
        double x,y; cin>>x>>y;
        if(x == -1 && y == -1)
            fix[i] = 0;
        A[i] = Point{x,y};
    }

    for(int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    for(int x=0; x<50000; x++) {
        for(int i=0; i<n; i++) {
            if(fix[i])
                B[i] = A[i];
            else {
                Point temp{0.0, 0.0};
                for(int j:G[i]) {
                    temp.x += A[j].x;
                    temp.y += A[j].y;
                }
                B[i].x = 0.5*A[i].x + 0.5*temp.x/G[i].size();
                B[i].y = 0.5*A[i].y + 0.5*temp.y/G[i].size();
            }
        }
        for(int j=0; j<n; j++)
            A[j] = B[j];
    }

    for(int i=0; i<n; i++)
        cout<<fixed<<setprecision(14)<<A[i].x<<" "<<A[i].y<<endl;
}