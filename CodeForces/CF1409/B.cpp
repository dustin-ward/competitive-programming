#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        long long a,b,x,y,n; cin>>a>>b>>x>>y>>n;
        
        if((a-x)+(b-y) <= n) {
            cout<<x*y<<endl;
            continue;
        }

        if(max(a-n,x) < max(b-n,y)) {
            long long lo = max(a-n,x);
            long long rem = n-(a-lo);
            long long hi = max(b-rem,y);
            //cout<<"lo "<<lo<<" hi "<<hi<<endl;
            cout<<lo*hi<<endl;
        }
        else {
            long long lo = max(b-n,y);
            long long rem = n-(b-lo);
            long long hi = max(a-rem,x);
            //cout<<"lo "<<lo<<" hi "<<hi<<endl;
            cout<<lo*hi<<endl;
        }
    }
}