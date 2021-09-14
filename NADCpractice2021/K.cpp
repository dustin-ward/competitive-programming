#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, N; cin>>W>>N;
    
    int area = 0;
    for(int i=0; i<N; i++) {
        int x,y; cin>>x>>y;
        area += x*y;
    }

    cout<<area/W<<endl;
}