#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Ping {
    ll p;
    ll x;
    ll y;
    ll t;
};

int main() {
    int P,N; cin>>P>>N;

    vector<Ping> pings;
    for(int i=0; i<N; i++) {
        ll p, x, y, t;
        cin>>p>>x>>y>>t;
        Ping p1 = {p, x, y, t};

        pings.push_back(p1);
    }

    sort(pings.begin(), pings.end(), [](Ping &a, Ping &b) {return a.t < b.t;});
    // for(auto i:pings)
    //     cout<<i.p<<" "<<i.x<<" "<<i.y<<" "<<i.t<<endl;

    set<pair<int,int>> S;
    for(int i=0; i<N; i++) {
        for(int j=1; j<=5; j++) {
            if(i+j >= N) break;

            if(abs(pings[i+j].t - pings[i].t) > 10) break;

            ll xDiff = abs(pings[i].x - pings[i+j].x) * abs(pings[i].x - pings[i+j].x);
            ll yDiff = abs(pings[i].y - pings[i+j].y) * abs(pings[i].y - pings[i+j].y);
            if(xDiff + yDiff <= 1000 * 1000) {
                if(pings[i].p != pings[i+j].p)
                    S.insert(make_pair(min(pings[i].p, pings[i+j].p), max(pings[i].p, pings[i+j].p)));
            }
        }
    }

    cout<<S.size()<<endl;
    for(auto i:S)
        cout<<i.first<<" "<<i.second<<endl;
}