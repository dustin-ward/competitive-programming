#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,N; cin>>X>>N;
    
    int c = X;
    for(int i=0; i<N; i++) {
        int P; cin>>P;
        c += X-P;
    }

    cout<<c<<endl;
}