#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N,M,L; cin>>N>>M>>L;
    vector<long long> cuts(M);

    map<long long,long long> folds;
    folds[0]++;
    bool r = true;
    long long pos = 0;
    long long start = 0;
    long long end = 0;
    long long lastF = L;
    for(int i=0; i<N; i++) {
        long long f; cin>>f;
        cout<<"f "<<f<<endl;
        long long loc;
        if(r) {
            loc = pos + (lastF - f);
            folds[loc] -= 2;
            cout<<"-2 at "<<loc<<endl;
        }
        else {
            loc = pos - (lastF - f);
            folds[loc] += 2;
            cout<<"+2 at "<<loc<<endl;
        }
        pos = loc;
        if(pos < start)
            start = pos;
        if(pos > end)
            end = pos;
        lastF = f;
        r = !r;
    }
    if(r) {
        cout<<"-1 at "<<pos+lastF<<endl;
        folds[pos+lastF]--;
    }
    else {
        cout<<"+1 at "<<pos-lastF<<endl;
        folds[pos-lastF]++;
    }

    for(int i=0; i<M; i++) {
        cin>>cuts[i];
    }
    cuts.push_back(end);

    long long distance = 0;
    long long count = 0;
    long long cut = 0;
    vector<long long> ans;
    for(auto it = folds.begin(); it != folds.end(); ++it) {
        cout<<"i "<<it->first<<" "<<it->second<<endl;
        cout<<"cut at "<<cuts[cut]<<endl;
        if(it->first > cuts[cut]) {
            ans.push_back(distance + ((cuts[cut] - pos) * count));
            cout<<"pushed "<<distance + ((cuts[cut] - pos) * count)<<endl;
            distance = (it->first - cuts[cut]) * count;
            cout<<(it->first - cuts[cut]) * count<<" left over"<<endl;
            cut++;
            it--;
        }
        else if(it->first == cuts[cut]) {
            ans.push_back(distance + ((it->first - pos) * count));
            cout<<"pushed "<<distance + ((it->first - pos) * count)<<endl;
            distance = 0;
            cout<<0<<" left over"<<endl;
            cut++;
            count += it->second;
        }
        else {
            distance += (it->first - pos) * count;
            cout<<(it->first - pos) * count<<" covered"<<endl;
            count += it->second;
        }
        pos = it->first;
    }
    if(cut != cuts.size()) {
        ans.push_back(distance);
        while(++cut < cuts.size()) {
            ans.push_back(0);
        }
    }

    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;

    for(auto i:folds)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
}