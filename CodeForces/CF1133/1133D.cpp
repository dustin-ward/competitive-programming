#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    vector<int> A(n);
    vector<int> B(n);
    for(int i=0; i<n; i++)
        cin>>A[i];
    for(int i=0; i<n; i++)
        cin>>B[i];

    int zero=0;
    map<pair<int,int>, int> m;
    for(int i=0; i<n; i++) {
        if(A[i] == 0 && B[i] == 0)
            zero++;
        else if(A[i] == 0)
            continue;
        else if(B[i] == 0)
            m[make_pair(1,0)]++;
        else {
            int d = __gcd(A[i], B[i]);
            m[make_pair(A[i]/d, B[i]/d)]++;
        }
    }

    int ans=0;
    for(auto i:m) {
        if(i.second > ans)
            ans = i.second;
    }

    cout<<ans+zero<<endl;
}