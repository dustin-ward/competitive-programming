#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,P,S; cin>>N>>P>>S;
    for(int i=0; i<S; i++) {
        int m; cin>>m;
        bool remove = true;
        for(int j=0; j<m; j++) {
            int c; cin>>c;
            if(c == P) {
                cout<<"KEEP"<<endl;
                remove = false;
            }
        }
        if(remove)
            cout<<"REMOVE"<<endl;
    }
}