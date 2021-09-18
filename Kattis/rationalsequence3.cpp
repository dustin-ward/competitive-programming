#include <bits/stdc++.h>
using namespace std;

int frac[] = {0, 1};

void f(int n) {
    if(n > 0)
        f(n/2);
    frac[~n & 1] += frac[n & 1]; 
}

int main() {
    int N;
    cin>>N;

    for(int i=0; i<N; i++) {
        int g, t;
        cin>>g>>t;
        f(t);
        cout<<g<<" "<<frac[0]<<"/"<<frac[1]<<endl;
        frac[0] = 0; frac[1] = 1;
    }
}