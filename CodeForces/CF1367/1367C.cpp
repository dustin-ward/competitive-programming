#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n,k; cin>>n>>k;
        string s; cin>>s;

        vector<int> v(n, 1);
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                for(int j=i; j<=i+k && j<n; j++)
                    v[j] = 0;
                //i += k+1;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '1') {
                for(int j=i; j>=i-k && j>=0; j--)
                    v[j] = 0;
                //i -= k+1;
            }
        }

        int ans=0;
        for(int i=0; i<n; i++) {
            if(v[i]) {
                ans++;
                i += k;
            }
        }

        // for(int i:v)
        //     cout<<i<<" ";
        // cout<<endl;

        cout<<ans<<endl;
        

    }
}