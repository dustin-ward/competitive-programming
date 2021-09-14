#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> days(365, 0);

    for(int i=0; i<N; i++) {
        int s,t; cin>>s>>t;
        for(int j=s-1; j<t; j++) {
            days[j] = 1;
        }
    }

    int ans=0;
    for(int i=0; i<365l; i++) {
        if(days[i]) ans++;
    }
    cout<<ans<<endl;
}