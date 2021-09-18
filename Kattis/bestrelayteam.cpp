#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<long double, string>> a, b;

    int n; cin>>n;
    for(int i=0; i<n; i++) {
        string name; cin>>name;
        long double ta, tb; cin>>ta>>tb;
        a.push_back(make_pair(ta, name));
        b.push_back(make_pair(tb, name)); 
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<string> bestTeam;
    long double bestTime = 81.0;
    for(int i=0; i<4; i++) {
        long double curTime = 0.0;
        vector<string> team;
        team.push_back(a[i].second);
        curTime += a[i].first;

        for(int j=0; j<b.size(); j++) {
            if(b[j].second != team[0]) {
                team.push_back(b[j].second);
                curTime += b[j].first;
            }
            if(team.size() == 4) break;
        }

        if(curTime < bestTime) {
            bestTeam = team;
            bestTime = curTime;
        }
    }

    cout<<bestTime<<endl;
    for(auto n:bestTeam)
        cout<<setprecision(9)<<fixed<<n<<endl;
}