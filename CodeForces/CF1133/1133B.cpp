#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;

    vector<int> v(k,0);
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        v[temp%k]++;
    }

    int ans = v[0]/2;
    for(int i=1; i<k/2; i++) {
        ans += min(v[i], v[k-i]);
    }
    if(k%2)
        ans += min(v[k/2], v[k-k/2]);
    else
        ans += v[k/2]/2;

    cout<<ans*2<<endl;
}