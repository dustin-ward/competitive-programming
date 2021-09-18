#include <bits/stdc++.h>
using namespace std;

int DFS(vector<vector<pair<int,int>>> &G, vector<bool> visited, int n, int s, int t, int k, int sum, int count) {
    if(count == k) return INT_MAX;
    visited[s] = 1;
    int ans = INT_MAX;
    for(auto p:G[s]) {
        if(visited[p.first]) continue;
        if(p.first == t) {
            ans = min(ans, sum + p.second);
        }
        else {
            ans = min(ans, DFS(G, visited, n, p.first, t, k, sum+p.second, count+1));
        }
    }
    return ans;
}

int main() {
    int TC; cin>>TC;
    while(TC--) {
        int V; cin>>V;
        vector<vector<pair<int, int>>> G(V, vector<pair<int,int>>());
        for(int i=0; i<V; i++) {
            int X; cin>>X;
            for(int j=0; j<X; j++) {
                int v,w; cin>>v>>w;
                G[i].push_back(make_pair(v,w));
            }
        }

        int Q; cin>>Q;
        while(Q--) {
            int s,t,k; cin>>s>>t>>k;
            if(s == t) {
                cout<<0<<endl;
                continue;
            }
            vector<bool> visited(V, 0);
            int ans = DFS(G, visited, V, s, t, k, 0, 1);
            cout<<((ans != INT_MAX) ? ans : -1)<<endl;
        }
        cout<<endl;
    }
}