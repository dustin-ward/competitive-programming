#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        long long s; cin>>s;
        long long spent=0;
        spent += (s/9) * 10;
        spent += s%9;
        if(s%9==0)
            spent--;
        // while(s) {
        //     if(s>=10) {
        //         s -= 9;
        //         spent += 10;
        //     }
        //     else {
        //         spent += s;
        //         s=0;
        //     }
        // }
        cout<<spent<<endl;
    }
}