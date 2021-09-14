#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int a,b; cin>>a>>b;
        int diff = abs(b-a);
        int ans = diff/10;
        if(diff%10)
            ans++;
        cout<<ans<<endl;
    }
}