#include <bits/stdc++.h>
using namespace std;

int main() {
    int M[9] = {11,23,38,89,186,308,200,464,416};

    int P; cin>>P;
    while(P--) {
        int G = 0;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                char c; cin>>c;
                if(c == '*')
                    G |= (1<<(i*3+j));
            }
        }

        vector<int> D(511, -1);
        queue<int> q;
        q.push(G);
        D[G] = 0;
        while(!q.empty()) {
            int x = q.front(); q.pop();
            for(int i=0; i<9; i++) {
                int next = x ^ M[i];
                if(D[next] == -1) {
                    q.push(next);
                    D[next] = D[x] + 1;
                }
            }
        }

        cout<<D[0]<<endl;
    }
}