#include <bits/stdc++.h>
using namespace std;

int main() {
    int x; cin>>x;
    int ans = INT_MAX;
    while(ans >= 10) {
        ans = 1;
        // cout<<"ans = "<<ans<<endl;
        while(x >= 10) {
            // cout<<"x = "<<x<<endl;
            if(x % 10)
                ans *= x % 10;
            x /= 10;
        }
        if(x)
            ans *= x;
        x = ans;
    }
    cout<<ans<<endl;
}