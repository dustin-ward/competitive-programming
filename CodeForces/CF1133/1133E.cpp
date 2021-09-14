#include <bits/stdc++.h>
using namespace std;

int v[5000];
int dp[5001][5001];

int f(int n, int k) {
    if(n == 0 || k == 0)
        return 0;
    if(dp[n][k] >= 0)
        return dp[n][k];

    // int t=n-1;
    // while(v[n]-v[t] <= 5 && t > 0)
    //     t--;
    int t = n - (lower_bound(v, v+n-1, v[n-1]-5) - v);
    dp[n][k] = max(f(n-1, k), t + f(n-t, k-1));
    return dp[n][k];
}

int main() {
    int n,k; cin>>n>>k;

    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    sort(v, v+n);

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            dp[i][j] = -1;
        }
    }

    cout<<f(n,k)<<endl;
}