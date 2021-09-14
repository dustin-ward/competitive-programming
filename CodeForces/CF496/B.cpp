#include <bits/stdc++.h>
using namespace std;

int main() {
    string s,t; cin>>s>>t;
    int sP=s.length()-1;
    int tP=t.length()-1;
    int common=0;
    
    while(sP >= 0 && tP >= 0 && s[sP] == t[tP]) {
        common++;
        sP--; tP--;
    }

    cout<<(s.length()+t.length())-(2*common)<<endl;
}