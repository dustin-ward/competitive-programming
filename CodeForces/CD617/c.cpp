#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        int lr=0, ud=0;
        for(int i=0; i<n; i++) {
            switch(s[i]) {
                case 'L':
                    lr--;
                    break;
                case 'R':
                    lr++;
                    break;
                case 'U':
                    ud++;
                    break;
                case 'D':
                    ud--;
                    break;
            }

            if()
        }
    }
}