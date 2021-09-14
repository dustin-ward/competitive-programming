#include <bits/stdc++.h>
using namespace std;

bool f(pair<int, int> p1, pair<int, int> p2) {
    // if(p1.first == p2.first) {
    //     return p1.second > p2.second;
    // }
    // else
    //     return p1.first < p2.first;
    return p1.second > p2.second
}

int main() {
    int N; cin>>N;

    vector<pair<int, int>> v;
    for(int i=0; i<N; i++) {
        int temp1, temp2; cin>>temp1>>temp2;

        v.push_back(make_pair(temp1,temp2));
    }

    sort(v.begin(), v.end(), f);

    int money=0;
    int time=0;
    for(auto i:v) {
        if(i.first >= time) {
            time = i.first;
            money += i.second;
        }
    }

    cout<<money<<endl;
}