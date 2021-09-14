#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T; cin>>N>>T;

    vector<pair<int,int>> P(N);
    for(int i=0; i<N; i++)
        cin>>P[i].second>>P[i].first;

    sort(P.rbegin(), P.rend());
    priority_queue<int> Q;

    int ans = 0;
    int i = 0;
    while(T >= 0) {
        while(P[i].first == T) {
            Q.push(P[i++].second);
        }
        if(Q.size()>0) {
            ans += Q.top();
            Q.pop();
        }
        T--;
    }
    cout<<ans<<endl;
}