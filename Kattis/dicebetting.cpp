#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dp(10001, vector<double>(501, -1.0));

double f(int n, int k, int s) {
    if(k == 0 || k > n)
        return 0.0;
    if(n == 1 && k == 1)
        return dp[n][k] = 1.0;
    if(dp[n][k] >= 0.0)
        return dp[n][k];

    dp[n][k] = f(n-1, k, s) * (double)k/s + f(n-1, k-1, s) * (double)(s-k+1)/s;
    return dp[n][k];
}

int main() {
    int n,k,s; cin>>n>>k>>s;

    double ans = 0.0;
    for (int i = k; i <= min(n,s); i++) {
        ans += f(n, i, s);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}