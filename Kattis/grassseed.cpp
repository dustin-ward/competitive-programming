#include <bits/stdc++.h>
using namespace std;

int main() {
    double C; cin>>C;
    int L; cin>>L;

    double ans = 0.0;

    for(int i=0; i<L; i++) {
        double w,h; cin>>w>>h;
        
        ans += w*h*C;
    }

    cout<<showpoint<<setprecision(10)<<ans<<endl;
}