#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n,l,d,g; cin>>n>>l>>d>>g;
        double initArea = (l*l*n) / (4.0*tan((180.0/n) * M_PI / 180.0));
        double area;
        
        if(!g) {
            cout<<setprecision(numeric_limits<double>::max_digits10)<<showpoint<<initArea<<endl;
            continue;
        }
        if(g>=1) {
            area = initArea + (n*l*(d*g)) + (M_PI*(d*g)*(d*g));

        }
        // for(int i=0; i<g; i++) {
        //     area *= d;
        // }

        cout<<setprecision(numeric_limits<double>::max_digits10)<<showpoint<<area<<endl;
    }
}