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

class UnionFind
{
    struct UF { int p; int rank; };

    public:
        UnionFind(int n) {          // constructor
            howMany = n;
            uf = new UF[howMany];
            for (int i = 0; i < howMany; i++) {
                uf[i].p = i;
                uf[i].rank = 0;
            }
        }

        ~UnionFind() {
            delete[] uf;
        }

        int find(int x) { return find(uf,x); }        // for client use
      
        bool merge(int x, int y) {
            int res1, res2;
            res1 = find(uf, x);
            res2 = find(uf, y);
            if (res1 != res2) {
                if (uf[res1].rank > uf[res2].rank) {
                    uf[res2].p = res1;
                }
                else {
                    uf[res1].p = res2;
                    if (uf[res1].rank == uf[res2].rank) {
                        uf[res2].rank++;
                    }
                }
                return true;
            }
            return false;
        }
      
    private:
        int howMany;
        UF* uf;

        int find(UF uf[], int x) {     // recursive funcion for internal use
            if (uf[x].p != x) {
                uf[x].p = find(uf, uf[x].p);
            }
            return uf[x].p;
        }
};

struct Edge {
    int u;
    int v;
    int w;
};

int main() {
    int N,M;
    while(cin>>N>>M && N) {
        vector<Edge> E(M);
        for(Edge &e:E) {
            int u,v; cin>>u>>v>>e.w;
            e.u = min(u,v);
            e.v = max(u,v);
        }

        sort(all(E), [](const Edge &a, const Edge &b){return a.w <= b.w;});

        int ans = 0;
        UnionFind uf(N);
        vector<Edge> mst;
        for(Edge &e:E) {
            if(uf.find(e.u) != uf.find(e.v)) {
                mst.push_back(e);
                ans += e.w;
                uf.merge(e.u,e.v);
            }
        }

        if(sz(mst) != N-1) {
            cout<<"Impossible"<<endl;
            continue;
        }

        sort(all(mst), [](const Edge &a, const Edge &b){
            if(a.u < b.u)
                return true;
            else if(a.u == b.u)
                return a.v < b.v;
            else
                return false;
        });
        cout<<ans<<endl;
        for(Edge &e:mst)
            cout<<e.u<<" "<<e.v<<endl;
    }
}
