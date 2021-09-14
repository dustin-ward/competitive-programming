#include <bits/stdc++.h>
using namespace std;

struct UF {
    vector<int> uf, cnt, idx;
    vector<long long> sum;
    int pos;

    UF(int n, int m) : uf(n+m+1), cnt(n+m+1), sum(n+m+1), idx(n+1) {
        pos = n+1;
        for(int i=0; i<n+1; i++) {
            uf[i] = i;
            cnt[i] = 1;
            sum[i] = i;
            idx[i] = i;
        }
        for(int i=n+1; i<n+m+1; i++) {
            uf[i] = i;
            cnt[i] = 1;
            sum[i] = 0;
        }
    }

    int find(int p) {
        return findR(idx[p]);
    }

    int findR(int p) {
        if(uf[p] == p)
            return p;
        else {
            uf[p] = findR(uf[p]);
            return uf[p];
        }
    }

    bool merge(int p, int q) {
        int P = find(p);
        int Q = find(q);
        if(P == Q)
            return false;
        else {
            uf[Q] = P;
            cnt[P] += cnt[Q];
            sum[P] += sum[Q];
            return true;
        }
    }

    bool move(int p, int q) {
        int P = find(p);
        int Q = find(q);
        if(P == Q)
            return false;
        else {
            cnt[P]--;
            sum[P] -= p;
            idx[p] = pos;
            sum[pos++] = p;
            merge(p, q);
            return true;
        }
    }
};

int main() {
    int n,m; 
    while(cin>>n>>m) {
        UF uf(n, m);

        for(int i=0; i<m; i++) {
            int c, p, q; cin>>c;
            switch(c) {
                case 1:
                    cin>>p>>q;
                    uf.merge(p, q);
                    break;
                case 2:
                    cin>>p>>q;
                    uf.move(p, q);
                    break;
                case 3:
                    cin>>p;
                    int r = uf.find(p);
                    cout<<uf.cnt[r]<<" "<<uf.sum[r]<<endl;
                    break;
            }
        }
    }
}