#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int x,y,n; cin>>x>>y>>n;

        int temp = n/x;
        int a1 = (temp*x)+y;
        int a2 = ((temp-1)*x)+y;

        if(a1 > n)
            cout<<a2<<endl;
        else
            cout<<a1<<endl;
    }
}