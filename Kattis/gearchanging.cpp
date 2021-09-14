#include <bits/stdc++.h>
using namespace std;

bool f(pair<int,int> &a, pair<int,int> &b) {
    return a.first * b.second < b.first * a.second;
}

int main() {
    int N,M,P; cin>>N>>M>>P;

    vector<int> C(N), D(M);
    for(int i=0; i<N; i++)
        cin>>C[i];
    for(int i=0; i<M; i++)
        cin>>D[i];

    vector<pair<int,int>> G;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            G.push_back(make_pair(C[i], D[j]));
        }
    }

    sort(G.begin(), G.end(), f);

    // cout<<"==============="<<endl;
    // for(auto i:G)
    //     cout<<i.first<<" "<<i.second<<endl;

    for(int i=0; i<G.size()-1; i++) {
        if(((G[i].second * G[i+1].first) - (G[i].first * G[i+1].second)) * 100 > G[i].first * G[i+1].second * P) {
            cout<<"Time to change gears!"<<endl;
            return 0;
        }
    }

    cout<<"Ride on!"<<endl;
}