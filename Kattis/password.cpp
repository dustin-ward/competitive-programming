#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    vector<double> v(N);
    for(int i=0; i<N; i++) {
        string s; cin>>s;
        cin>>v[i];
    }
    sort(v.rbegin(), v.rend());
    double ans=0.0;
    for(int i=0; i<N; i++) {
        ans += (i+1.0)*v[i];
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
}