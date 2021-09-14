#include <bits/stdc++.h>
using namespace std;

#define E 1000000007

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        int nx, x = 0;
        int no, o = 0;
        int nf, f = 0;
        int nsub, sub = 0;
        int ntotal, total = 0;

        int N; cin>>N;
        for(int i=1; i<=N; i++) {
            char c; cin>>c;
            switch(c) {
                case 'F':
                    nx = x;
                    no = o;
                    nf = f + 1;
                    nsub = sub;
                    ntotal = total + sub;
                    break;
                case 'X':
                    nx = x + o + f + 1;
                    no = 0;
                    nf = 0;
                    nsub = sub + o;
                    ntotal = total + sub + o;
                    break;
                case 'O':
                    nx = 0;
                    no = o + x + f + 1;
                    nf = 0;
                    nsub = sub + x;
                    ntotal = total + sub + x;
                    break;
            }
            x = nx;
            o = no;
            f = nf;
            sub = nsub % E;
            total = ntotal % E;
        }
        cout<<"Case #"<<caseno++<<": "<<total<<endl;
    }
}