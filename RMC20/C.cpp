#include <bits/stdc++.h>
using namespace std;

struct Event {
    int fold = 0;
    int cut = 0;
};

int main() {
    long long N,M,L; cin>>N>>M>>L;
    map<long long, Event> events;
    events[0].fold++;

    bool r = true;
    long long pos = 0;
    // long long end = 0;
    long long lastF = L;
    for(int i=0; i<N; i++) {
        long long f; cin>>f;
        long long loc;
        if(r) {
            loc = pos + (lastF - f);
            events[loc].fold -= 2;
            // cout<<"-2 at "<<loc<<endl;
        }
        else {
            loc = pos - (lastF - f);
            events[loc].fold += 2;
            // cout<<"+2 at "<<loc<<endl;
        }
        pos = loc;
        // if(pos < start)
        //     start = pos;
        // if(pos > end)
        //     end = pos;
        lastF = f;
        r = !r;
    }
    // NEED TO FIX ENDING LEFT
    if(r) {
        events[pos + (lastF - f)].fold -= 2;
    }
    else {
        events[pos - (lastF - f)].fold += 2;
    }

    for(int i=0; i<M; i++) {
        long long c; cin>>c;
        events[c].cut = 1;
    }
    // events[end].cut++;

    for(auto i:events)
        cout<<i.first<<" "<<i.second.fold<<" "<<i.second.cut<<endl;

    long long distance = 0;
    long long total = 0;
    int count = 0;
    long long lastPos = events.begin()->first;
    vector<long long> ans;
    for(auto i:events) {
        // cout<<"distance "<<distance<<endl;
        distance += (count * (i.first - lastPos));
        // cout<<"at "<<i.first<<" "<<i.second.fold<<" "<<i.second.cut<<endl;
        // cout<<"+= "<<count<<" * "<<i.first<<" - "<<lastPos<<endl;
        if(i.second.cut) {
            ans.push_back(distance);
            // cout<<"pushed"<<endl;
            total += distance;
            distance = 0;
        }
        count += i.second.fold;
        lastPos = i.first;
        // cout<<"fold "<<count<<endl;
    }
    ans.push_back(L-total);

    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}