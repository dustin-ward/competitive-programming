#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
bool marked[200000];

void dfs(int n) {
    marked[n] = true;

    for(int i:G[n]) {
        if(!marked[i])
            dfs(i);
    }
}

int main() {
    int N,M; cin>>N>>M;
    G.resize(N);

    for(int i=0; i<M; i++) {
        int x,y; cin>>x>>y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }    

    dfs(0);

    bool flag = true;
    for(int i=0; i<N; i++) {
        if(!marked[i]) {
            flag = false;
            cout<<i+1<<endl;
        }
    }

    if(flag) {
        cout<<"Connected"<<endl;
    }
}