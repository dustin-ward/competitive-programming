#include <bits/stdc++.h>
using namespace std;

int DFS(vector<int> v, vector<int> v, vector<int> v, vector<int> v, vector<int> v, ) {

}

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> x(n);
        vector<int> y(n);

        for(int i=0; i<n; i++) {
            int ta, tb, tx, ty;
            cin>>ta>>tb>>tx>>ty;
            a[i] = ta;
            b[i] = tb;
            x[i] = tx;
            y[i] = ty;
        }

        vector<int> v(150000, 0);

        cout<<DFS(v, a, b, x, y, i)<<endl;

    }

}