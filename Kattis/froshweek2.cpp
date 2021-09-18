#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    priority_queue<int> t,l;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        t.push(temp);
    }
    for(int j=0; j<m; j++) {
        int temp; cin>>temp;
        l.push(temp);
    }

    int ans = 0;
    while(!t.empty() && !l.empty()) {
        // cout<<"t "<<t.top()<<endl;
        // cout<<"l "<<l.top()<<endl;
        if(t.top() <= l.top()) {
            // cout<<"good"<<endl;
            ans++;
            t.pop();
            l.pop();
        }
        else {
            t.pop();
        }
    }

    cout<<ans<<endl;
}