#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        string ans = "";
        for(int i=0; i<s.length()-1; i+=2) {
            ans = ans + s[i];
        }
        ans = ans + s[s.length()-1];
        cout<<ans<<endl;
    }
}