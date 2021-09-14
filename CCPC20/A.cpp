#include <bits/stdc++.h>
using namespace std;

int main() {
    int k,m,n; cin>>k>>m>>n;

    if(k <= n && k >= m) {
        cout<<"Alex"<<endl;
        return 0;
    }
    if(k < m) {
        cout<<"Barb"<<endl;
        return 0;
    }

    int x = (k-n)%(m+n);
    if(x < n)
        cout<<"Barb"<<endl;
    else
        cout<<"Alex"<<endl;
}