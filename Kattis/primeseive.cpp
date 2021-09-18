#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q; cin>>n>>q;
    vector<bool> prime(100000001, 1);
    prime[1] = 0;

    for(int i=2; i*i <= n; i++) {
        if (prime[i]) {
            for (int j=i*i; j <= n; j += i)
                prime[j] = 0;
        }
    }
    
    int ans = 0;
    for(int i=1; i<=n; i++)
        if(prime[i]) ans++;
    cout<<ans<<endl;

    for(int i=0; i<q; i++) {
        int x; cin>>x;
        cout<<prime[x]<<endl;
    }
}