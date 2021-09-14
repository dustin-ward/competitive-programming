#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,r; cin>>n>>r;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    int ans=0;
    int next=0;
    while(next < n) {
        bool flag = false;
        for(int i = next + r-1; i>= next - r+1 && !flag; i--) {
            if(i < 0 || i >= n)
                continue;
            if(v[i]) {
                ans++;
                next = i+r;
                flag = true;
            }
        }
        if(!flag) {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}