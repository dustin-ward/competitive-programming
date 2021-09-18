#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    double ans = 0.0;
    for(int i=0; i<N; i++) {
        double q,y; cin>>q>>y;
        ans += q*y;
    }
    cout<<fixed<<setprecision(5)<<ans<<endl;
}