#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<long long> c(n);
    for(int i=0; i<n; i++) {
        cin>>c[i];
    }

    sort(c.begin(), c.end());
    // for(auto i:c)
        // cout<<i<<" ";
    // cout<<endl;

    int lo=0, hi=c.size()-1, mid;
    while (lo <= hi) {
        if (c[mid = (hi + lo) / 2] < c.size() - mid) lo = mid + 1;
        else hi = mid - 1;
    }
    cout<<c.size()-lo<<endl;
}