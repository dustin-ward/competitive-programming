#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int to;
    int w;
    Edge(int a, int b) : to{a}, w{b} {}
};

void dijkstra(vector<vector<Edge>> &G, int start, vector<ll> &D) {
    typedef pair<ll, int> plli;
    priority_queue<plli, vector<plli>, greater<plli>> P;

    vector<int> N(G.size(), 0);

    D[start] = 0;
    P.push(make_pair(0, start));

    while(!P.empty()) {
        plli next = P.top(); P.pop();

        int w = next.second;
        if(!N[w]) {
            N[w] = 1;
            for(int i=0; i<G[w].size(); i++) {
                int z = G[w][i].to;
                if(!N[z]) {
                    if(D[z] > D[w] + G[w][i].w) {
                        D[z] = D[w] + G[w][i].w;
                        P.push(make_pair(D[z], z));
                    }
                }
            }
        }
    }
}

int main() {
    int T, caseno=1; cin>>T;
    while(T--) {
        int N,M; cin>>N>>M;
        
        vector<ll> D(N*(M+1), LLONG_MAX);
        vector<vector<Edge>> G(N*(M+1));
        for(int i=0; i<N-1; i++) {
            for(int j=1; j<=M; j++) {
                G[(i*(M+1))+j].push_back(Edge(((i+1)*(M+1))+(j-1), 0));
            }
        }

        for(int i=0; i<N; i++) {
            int C; cin>>C;
            if(C) {
                int d = ((i+1)*(M+1))-1;
                for(int j=0; j<M; j++) {
                    G[(i*(M+1))+j].push_back(Edge(d, C));
                }
            }
        }

        dijkstra(G, M-1, D);

        ll ans = LLONG_MAX;
        // cout<<"D -------"<<endl;
        for(int i=(N-1)*(M+1); i<N*(M+1); i++) {
            // cout<<D[i]<<" ";
            if(D[i] < ans)
                ans = D[i];
        }
        // cout<<endl;
        cout<<"Case #"<<caseno++<<": "<<((ans < LLONG_MAX) ? ans : -1)<<endl;

        // cout<<"GRAPH ----------------"<<endl;
        // for(int i=0; i<N*(M+1); i++) {
        //     for(int j=0; j<G[i].size(); j++) {
        //         cout<<i<<" -> "<<G[i][j].to<<" "<<G[i][j].w<<" , ";
        //     }
        //     cout<<endl;
        // }
    }
}