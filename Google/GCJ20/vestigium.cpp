#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        int N; cin>>N;
        vector<vector<int>> M(N, vector<int>(N));
        vector<vector<int>> cols(N, vector<int>(N+1, 0));
        vector<vector<int>> rows(N, vector<int>(N+1, 0));

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                int temp; cin>>temp;
                if(rows[j][temp])
                    rows[j][0] = 1;
                if(cols[i][temp])
                    cols[i][0] = 1;
                M[i][j] = temp;
                rows[j][temp] = 1;
                cols[i][temp] = 1;
            }
        }

        int trace=0, r=0, c=0;
        for(int i=0; i<N; i++) {
            trace+= M[i][i];
            if(rows[i][0])
                r++;
            if(cols[i][0])
                c++;
        }

        cout<<"Case #"<<caseno++<<": "<<trace<<" "<<c<<" "<<r<<endl;
    }
}