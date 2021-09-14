#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int w;
    Edge(int a, int b) : to{a}, w{b} {}
};

void dijkstra(vector<vector<Edge>> &G, int start, vector<long long> &D) {
    typedef pair<long long, int> plli;
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

void artDFS(vector<vector<Edge>> &G, int u, vector<int> &visited, vector<int> &in, 
                        vector<int> &lo, vector<int> &p, vector<int> &ap, int &time) {
    int children = 0;
    in[u] = lo[u] = time++;
    visited[u] = 1;
    for(int i=0; i<G[u].size(); i++) {
        Edge e = G[u][i];
        if(!visited[e.to]) {
            children++;
            p[e.to] = u;
            artDFS(G, e.to, visited, in, lo, p, ap, time);

            lo[u] = min(lo[u], lo[e.to]);
            if(p[u] != -1 && lo[e.to] >= in[u])
                ap[u] = 1;
        }
        else if(e.to != p[u]) {
            lo[u] = min(lo[u], in[e.to]);
        }
    }
}

int main() {
    int N,M; cin>>N>>M;

    // Create Init Graphs
    vector<vector<Edge>> G(N);
    vector<vector<Edge>> revG(N);
    for(int i=0; i<M; i++) {
        int u,v,w; cin>>u>>v>>w;
        
        G[u].push_back(Edge(v,w));
        revG[v].push_back(Edge(u,w));
    }

    // Read start and end
    int s,t; cin>>s>>t;

    // Find distance from every vertice to start and end
    vector<long long> D(N, LLONG_MAX);
    vector<long long> revD(N, LLONG_MAX);
    dijkstra(G, s, D);
    dijkstra(revG, t, revD);

    // Make new graph with edges that exist in shortest path
    vector<vector<Edge>> minG(N);
    for(int i=0; i<G.size(); i++) {
        for(int j=0; j<G[i].size(); j++) {
            Edge e = G[i][j];
            if(D[i] + e.w + revD[e.to] == D[t]) {
                minG[i].push_back(Edge(e.to, e.w));
                minG[e.to].push_back(Edge(i, e.w));
            }
        }
    }

    // Find articulation points
    vector<int> visited(minG.size(), 0);
    vector<int> in(minG.size(), 0);
    vector<int> lo(minG.size(), 0);
    vector<int> p(minG.size(), -1);
    vector<int> ap(minG.size(), 0);
    ap[s] = 1; ap[t] = 1;
    int time = 0;
    for(int i=0; i<G[s].size(); i++) {
        if(!visited[G[s][i].to])
            artDFS(minG, s, visited, in, lo, p, ap, time);
    }

    // Output
    for(int i=0; i<ap.size(); i++) {
        if(ap[i]) 
            cout<<i<<" ";
    }
    cout<<endl;
}