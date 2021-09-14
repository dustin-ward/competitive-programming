#include <bits/stdc++.h>
using namespace std;

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

struct edge {
    int u;
    int v;
    int w;
};

int main() {
    int n,m;
    while(cin>>n>>m && n) {
        vector<edge> edges(m);
        for(int i=0; i<m; i++) {
            int u,v,w;
            cin>>u>>v>>w;
            edge e = {
                (u < v) ? u : v,
                (u < v) ? v : u,
                w
            };
            edges[i] = e;
        }

        sort(edges.begin(), edges.end(), [](edge &a, edge &b) {return a.w <= b.w;});

        int ans = 0;
        UnionFind uf = UnionFind(n);
        vector<edge> mst;
        for(auto e : edges) {
            if(uf.find(e.u) != uf.find(e.v)) {
                mst.push_back(e);
                ans += e.w;
                uf.merge(e.u, e.v);
            }
        }

        sort(mst.begin(), mst.end(), [](edge &a, edge &b) {
            if(a.u < b.u)
                return true;
            else if(a.u == b.u) {
                return a.v <= b.v;
            }
            else
                return false;
        });

        bool possible = true;
        for(int i=0; i<n; i++) {
            if(uf.find(i) != uf.find(0)) {
                cout<<"Impossible"<<endl;
                possible = false;
                break;
            }
        }
        if(possible) {
            cout<<ans<<endl;
            for(auto &e : mst)
                cout<<e.u<<" "<<e.v<<endl;
        }
    }
}