#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int ans=0;
    for(int p1=0, p2=0; p1<n; p1++) {
        if(p2<=p1) p2 = p1+1;
        while(p2<n && v[p2]-v[p1] <= 5)
            p2++;

        if(p2-p1 > ans)
            ans = p2-p1;
    }

    cout<<ans<<endl;
}