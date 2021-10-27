#include<bits/stdc++.h>
using namespace std;

int main() {
    int T,caseno=1; cin>>T;
    while(T--) {
        int R,C; cin>>R>>C;
        vector<vector<char>> G(R, vector<char>(C));
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++)
                cin>>G[i][j];
        }

        cout<<"Test "<<caseno++<<endl;
        for(int i=R-1; i>=0; i--) {
            for(int j=C-1; j>=0; j--)
                cout<<G[i][j];
            cout<<endl;
        }
    }
}