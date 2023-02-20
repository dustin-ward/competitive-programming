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
     size = new int[howMany];
	 for (int i = 0; i < howMany; i++) {
	    uf[i].p = i;
	    uf[i].rank = 0;
        size[i] = 1;
	 }
      }

      ~UnionFind() {
         delete[] uf;
         delete[] size;
      }

      int find(int x) { return find(uf,x); }        // for client use
      
      bool merge(int x, int y) {
	 int res1, res2;
	 res1 = find(uf, x);
	 res2 = find(uf, y);
	 if (res1 != res2) {
	    if (uf[res1].rank > uf[res2].rank) {
	       uf[res2].p = res1;
           size[res1] += size[res2];
	    }
	    else {
	       uf[res1].p = res2;
           size[res2] += size[res1];
	       if (uf[res1].rank == uf[res2].rank) {
		  uf[res2].rank++;
	       }
	    }
	    return true;
	 }
	 return false;
      }
      
      int* size;
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

    bool operator<(const Edge &b) {
        return w < b.w;
    }
};

struct Query {
    int a;
    int b;
    int l;
    int r;
    int m;
    void updateM() {
        m = (l+r)/2;
    }

    bool operator<(const Query &q) const {
        if(m == q.m) {
            if(a==q.a)
                return b<q.b;
            return a<q.a;
        }
        return m < q.m;
    }

};

ostream& operator<<(ostream& os, const Query q) {
    os << "A:"<<q.a<<" B:"<<q.b<<" (L:"<<q.l<<" R:"<<q.r<<" M:"<<q.m<<")";
    return os;
}

int N,M,Q;
vector<vector<Edge>> E;
vector<Query> Queries,QR;
map<pii,pii> ans;

int main() {
    cin>>N>>M>>Q;

    vector<Edge> all_edges(M);
    for(Edge &e:all_edges)
        cin>>e.u>>e.v>>e.w;
    sort(all(all_edges));

    for(int i=0; i<M; ++i) {
        if(!sz(E) || E[sz(E)-1][0].w!=all_edges[i].w)
            E.push_back(vector<Edge>());
        E[sz(E)-1].push_back(all_edges[i]);
    }

    set<Query> S;
    Queries.resize(Q);
    for(Query &q:Queries) {
        cin>>q.a>>q.b;
        q.l=0;
        q.r=sz(E);
        q.updateM();
        QR.push_back(q);
        S.insert(q);
    }

    while(sz(ans)<sz(S)) {
        UnionFind uf(N+1);
        sort(all(QR));
        int qi = 0;
        for(int i=0; i<sz(E); ++i) {
            for(Edge &e:E[i])
                uf.merge(e.u,e.v);

            while(qi<sz(QR)) {
                pii p = {QR[qi].a,QR[qi].b};
                if(ans.count(p)) {
                    qi++;
                    continue;
                }
                if(QR[qi].m > i) break;
                if(QR[qi].m < i) {
                    qi++;
                    continue;
                }

                if(QR[qi].l==QR[qi].r) {
                    pii p = {QR[qi].a,QR[qi].b};
                    ans[p] = {E[i][0].w, uf.size[uf.find(QR[qi].a)]};
                    qi++;
                    continue;
                }

                if(uf.find(QR[qi].a)==uf.find(QR[qi].b))
                    QR[qi].r=QR[qi].m;
                else
                    QR[qi].l=QR[qi].m+1;
                QR[qi].updateM();

                qi++;
            }
            if(qi==sz(QR)) break;
        }
    }

    for(Query &q:Queries) {
        pii p = {q.a,q.b};
        cout<<ans[p].fst<<" "<<ans[p].snd<<endl;
    }
}
