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
                uf[x].p = uf[uf[x].p].p;
                uf[x].p = find(uf, uf[x].p);
            }
            return uf[x].p;
        }
};

int main() {
    int n,q;
    cin>>n>>q;
    UnionFind uf = UnionFind(n);
    string ans = "";
    for(int i=0; i<q; i++) {
        char c;
        int a,b;
        cin>>c>>a>>b;
        
        if(c == '=') {
            uf.merge(a,b);
        } else {
            ans += ((uf.find(a) == uf.find(b)) ? "yes\n" : "no\n");
        }
    }
    cout<<ans<<endl;
}