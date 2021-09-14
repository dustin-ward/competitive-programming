#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,s,q; cin>>t>>s>>q;

    int plays = 1;
    while(q*s < t) {
        plays++;
        s *= q;
    }
    cout<<plays<<endl;
}