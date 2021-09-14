#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void f(vector<pii>& P, int l, int r, int t, int b) {
    if(l == r)
        return;
    
    int midX = (l+r)/2;
    int midY = (b+t)/2;

    vector<pii> Q[4];

    for(int i=0; i<P.size(); i++) {
        if(P[i].first > midX) {
            if(P[i].second > midY)
                Q[2].push_back(P[i]);
            else {
                Q[3].push_back(make_pair(r-(P[i].second-b), t-(P[i].first-l)));
            }
        }
        else { // P[i].first <= midX
            if(P[i].second > midY)
                Q[1].push_back(P[i]);
            else {
                int x=(P[i].second-b)+l;
                int y=(P[i].first-l)+b;
                Q[0].push_back(make_pair(x, y));
            }
        }
    }

    if(!Q[0].empty())
        f(Q[0], l, midX, midY, b);
    if(!Q[1].empty())
        f(Q[1], l, midX, t, midY+1);
    if(!Q[2].empty())
        f(Q[2], midX+1, r, t, midY+1);
    if(!Q[3].empty())
        f(Q[3], midX+1, r, midY, b);

    // Convert Back
    for(pii i:Q[0]) {
        int t1=i.first, t2=i.second;
        i.first = (t2-b)+l;
        i.second = (t1-l)+b;
    }

    for(pii i:Q[3]) {
        int t1=i.first, t2=i.second;
        i.first = r-(t2-b);
        i.second = t-(t1-l);
    }

    int idx = 0;
    for(int i=0; i<4; i++) {
        for(auto p:Q[i]) {
            P[idx++] = p;
        } 
    }
}

int main() {
    int n,s; cin>>n>>s;
    vector<pii> P;

    for(int i=0; i<n; i++) {
        int x,y; cin>>x>>y;
        P.emplace_back(x,y);
    }

    f(P,0,s,s,0);

    // cout<<"ANSWER"<<endl;
    for(pii i:P)
        cout<<i.first<<" "<<i.second<<endl;
}