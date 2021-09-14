#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        int N,M,A,B; cin>>N>>M>>A>>B;

        bool possible = true;
        vector<vector<int>> g(N, vector<int>(M, 1));
        g[0][0] = A - ((N-1) + (M-1));
        g[0][M-1] = B - ((N-1) + (M-1));
        if(g[0][0] <= 0 || g[0][M-1] <= 0) possible = false;

        cout<<"Case #"<<caseno++<<": ";
        if(possible) {
            cout<<"Possible"<<endl;
            for(auto v:g) {
                for(auto i:v)
                    cout<<i<<" ";
                cout<<endl;
            }
        }
        else
            cout<<"Impossible"<<endl;
    }
}