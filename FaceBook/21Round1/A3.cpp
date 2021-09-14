#include <bits/stdc++.h>
using namespace std;

#define E 1000000007
#define vvi vector<vector<unsigned long long>>

vvi F = {{1, 1, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0},
         {0, 0, 1, 0, 0, 0},
         {0, 0, 0, 1, 0, 1},
         {0, 0, 0, 0, 1, 0},
         {0, 0, 0, 0, 0, 1}};

vvi O = {{1, 1, 0, 0, 1, 0},
         {0, 1, 0, 0, 1, 0},
         {0, 0, 1, 1, 1, 1},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 1}};

vvi X = {{1, 1, 1, 0, 0, 0},
         {0, 1, 1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 1, 1, 1, 1},
         {0, 0, 0, 0, 0, 1}};

vvi multiply(vvi &a, vvi &b) {
    vvi ans(6, vector<unsigned long long>(6, 0));
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            for(int k=0; k<6; k++) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= E;
            }
        }
    }
    return ans;
}

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        vvi T = {{1, 0, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 1}};

        int N; cin>>N;
        for(int i=0; i<N; i++) {
            char c; cin>>c;
            switch(c) {
                case 'F':
                    T = multiply(F, T);
                    break;
                case 'X':
                    T = multiply(X, T);
                    break;
                case 'O':
                    T = multiply(O, T);
                    break;
                case '.':
                    T = multiply(T, T);
            }
        }

        cout<<"Case #"<<caseno++<<": "<<T[0][5]%E<<endl;
    }
}