#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    int winners = 0;

    set<string> uni;
    for(int i=0; i<N; i++) {
        string uniName, teamName; cin>>uniName>>teamName;
        if(uni.find(uniName) != uni.end() || winners >= 12)
            continue;
        uni.insert(uniName);
        cout<<uniName<<" "<<teamName<<endl;
        winners++;
    }
}