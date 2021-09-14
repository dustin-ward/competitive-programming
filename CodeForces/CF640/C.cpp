#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n,k; cin>>n>>k;
        int ans=1;
        for(int i=0; i<k; i++) {
            ans++;
            if(!(ans%k))
                i--;
        }

        cout<<ans<<endl;
    }
}