#include <bits/stdc++.h>
using namespace std;

int main() {
    int C;
    while(cin>>C && C) {
        map<string, int> m;
        for(int i=0; i<C; i++) {
            string s; cin>>s;
            m[s] = i;
        }

        vector<vector<double>> G(C, vector<double>(C));
        int R; cin>>R;
        for(int i=0; i<R; i++) {
            string c1, c2; cin>>c1>>c2;
            char _c;
            double x, y; cin>>x>>_c>>y;
            G[m[c1]][m[c2]] = y/x;
        }

        for(int i=0; i<C; i++) {
            for(int j=0; j<C; j++) {
                for(int k=0; k<C; k++)
                    G[i][j] = max(G[i][j], G[i][k] * G[k][j]);
            }
        }

        bool arbitrage = false;
        for(int i=0; i<C; i++) {
            if(G[i][i] > 1.0) {
                cout<<"Arbitrage"<<endl;
                arbitrage = true;
                break;
            }
        }

        if(!arbitrage)
            cout<<"Ok"<<endl;
    }
}