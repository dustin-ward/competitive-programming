#include <bits/stdc++.h>
using namespace std;

int main() {
    int c; cin>>c;
    while(c--) {
        int l,n; cin>>l>>n;
        int lo,hi;
        int earliest=0, latest=0;
        for(int i=0; i<n; i++) {
            int p; cin>>p;
            lo = min(p, l-p);
            hi = max(p, l-p);
            earliest = max(earliest, lo);
            latest = max(latest, hi);
        }
        cout<<earliest<<" "<<latest<<endl;
    }
}