#include <bits/stdc++.h>
using namespace std;

vector<int> dp(4712, -1);

int f(int n) {
    if(n == 1)
        return 0;
    if(dp[n] >= 0)
        return dp[n];
    
    int minTest = n-1;
    for(int i=1; i<n; i++) {
        minTest = min(minTest, 1+max(i-1, f(n-i)));
    }

    return dp[n] = minTest;
}

int main() {
    int n;
    while(cin>>n && n) {
        cout<<f(n)<<endl;
    }
}