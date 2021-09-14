#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    int p = 1, d=0;
    while(p < n) {
        d++;
        p*=2;
    }
    cout<<d+1<<endl;
}