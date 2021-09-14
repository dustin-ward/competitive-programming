#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    for(int i=0; i<N; i++) {
        double b,p; cin>>b>>p;
        cout<<fixed<<setprecision(7)<<60*(b-1)/p<<" "<<60*b/p<<" "<<60*(b+1)/p<<endl;
    }
}