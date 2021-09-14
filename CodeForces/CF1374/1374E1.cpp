#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;

    vector<int> A,B,Both;
    for(int i=0; i<n; i++) {
        int t, a, b; cin>>t>>a>>b;
        if(a && b)
            Both.push_back(t);
        else if(a)
            A.push_back(t);
        else if(b)
            B.push_back(t);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i=0; i<min(A.size(), B.size()); i++) {
        Both.push_back(A[i]+B[i]);
    }

    sort(Both.begin(), Both.end());
    
    if(Both.size() < k) {
        cout<<-1<<endl;
    }
    else {
        int ans = 0;
        for(int i=0; i<k; i++) {
            ans += Both[i];
        }

        cout<<ans<<endl;
    }
}