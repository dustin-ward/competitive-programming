#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin>>N>>M;

    vector<vector<int>> G(N, vector<int>());
    vector<int> army(N);
    vector<int> visited(N, 0);
    vector<int> queued(N, 0);
    for(int i=0; i<M; i++) {
        int x,y; cin>>x>>y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }

    for(int i=0; i<N; i++) {
        cin>>army[i];
    }

    priority_queue<pair<int,int>> q;
    int ans = army[0];
    visited[0] = 1;
    queued[0] = 1;
    for(int i=0; i<G[0].size(); i++) {
        // cout<<"ADDING "<<G[0][i]+1<<endl;
        q.push(make_pair(-army[G[0][i]], G[0][i]));
        queued[G[0][i]] = 1;
    }
    while(!q.empty()) {
        pair<int,int> x = q.top();
        q.pop();
        // cout<<"ON ISLAND"<<x.second+1<<endl;
        visited[x.second] = 1;
        // cout<<"CHECKING "<<ans<<" > "<<-x.first<<endl;
        if(ans > -x.first) {
            // cout<<"GOOD"<<endl;
            ans += army[x.second];
            for(int i=0; i<G[x.second].size(); i++) {
                if(!visited[G[x.second][i]] && !queued[G[x.second][i]]) {
                    // cout<<"ADDING "<<G[x.second][i]+1<<endl;
                    q.push(make_pair(-army[G[x.second][i]], G[x.second][i]));
                    queued[G[x.second][i]] = 1;
                }
            }
        }
    }
    cout<<ans<<endl;

}