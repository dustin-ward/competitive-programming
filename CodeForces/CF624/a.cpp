#include <bits/stdc++.h>
using namespace std;

int main() {
    int c; cin>>c;
    while(c--) {
        int a,b; cin>>a>>b;
        int dif = abs(a-b);

        if(a==b)
            cout<<0<<endl;
        else if(dif%2) {
            if(a>b)
                cout<<2<<endl;
            else
                cout<<1<<endl;
        }
        else {
            if(a>b)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
    }

}