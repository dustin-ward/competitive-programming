#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, caseno = 1; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<int> I(N), O(N);
        vector<vector<int>> P(N, vector<int>(N, 1));

        for(int i=0; i<N; i++) {
            char c; cin>>c;
            I[i] = (c == 'Y') ? 1 : 0;
        }
        for(int i=0; i<N; i++) {
            char c; cin>>c;
            O[i] = (c == 'Y') ? 1 : 0;
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                P[i][j] = (i == j) ? 1 : ((O[i] && I[j]) && abs(i-j)<=1);

            int x=i+1, y=i;
            while(I[x] && O[y] && x<N) {
                P[i][x] = 1;
                x++; y++;
            }
            x=i-1; y=i;
            while(I[x] && O[y] && x>=0) {
                P[i][x] = 1;
                x--; y--;
            }
        }

        cout<<"Case #"<<caseno++<<": "<<endl;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout<<((P[i][j]) ? "Y" : "N");
            }
            cout<<endl;
        }
    }
}