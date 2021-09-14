#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> poly(n+1);
    for(int i=0; i<=n; i++)
        cin>>poly[i];
    reverse(poly.begin(), poly.end());

    cout<<"POLY"<<endl;
    for(int i:poly)
        cout<<i<<" ";
    cout<<endl;

    vector<int> px(n+1);
    for(int i=0; i<=n; i++) {
        int ans = 0;
        for(int j=0; j<=n; j++) {
            cout<<"adding "<<poly[j]<<" * "<<i<<"^"<<j<<" = "<<poly[j] * pow(i, j)<<endl;
            ans += poly[j] * pow(i, j);
        }
        px[i] = ans;
        cout<<"px["<<i<<"] = "<<px[i]<<endl;
    }

    cout<<"PX"<<endl;
    for(int i:px)
        cout<<i<<" ";
    cout<<endl;

    int last = 0;
    for(int i:px) {
        cout<<i-last<<" ";
        last = i;
    }
    cout<<endl;
}