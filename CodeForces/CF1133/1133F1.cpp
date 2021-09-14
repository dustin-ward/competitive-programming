#include <bits/stdc++.h>
using namespace std;

// LIBRARY CODE
//
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

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> G(n+1);

    for(int i=0; i<m; i++) {
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int max=0;
    for(int i=1; i<=n; i++) {
        if(G[i].size() > G[max].size())
            max = i;
    }

    UnionFind UF(n+1);
    for(int i=0; i<G[max].size(); i++) {
        UF.merge(max, G[max][i]);
        cout<<max<<" "<<G[max][i]<<endl;
    }

    for(int i=0; i<=n; i++) {
        for(int j=0; j<G[i].size(); j++) {
            if(UF.find(i) != UF.find(G[i][j])) {
                UF.merge(i, G[i][j]);
                cout<<i<<" "<<G[i][j]<<endl;
            }
        }
    }

}