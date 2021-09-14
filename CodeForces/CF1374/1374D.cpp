#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        vector<int> mod(200000, 0);
        int n,k; cin>>n>>k;

        for(int i=0; i<n; i++) {
            int temp; cin>>temp;
            mod[temp%k]++;
        }

        int maxMod = 0;
        int maxPos = 0;
        for(int i=0; i<k; i++) {
            if(mod[i] >= maxMod) {
                maxMod = mod[i];
                maxPos = i;
            }
        }

        if(maxPos == 0) 
            cout<<0<<endl;
        else {
            long long ans = ((maxMod-1)*k) + (k-(maxPos-1));
            cout<<ans<<endl;
        }
    }
}