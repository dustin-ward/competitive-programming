#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans=0;
    int lo, hi;
    char c, k;
    string s;
    while(cin>>lo>>c>>hi>>k>>c>>s) {
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == k)
                count++;
        }
        if(count >= lo && count <= hi)
            ans++;
    }
    cout<<"ANSWER: "<<ans<<endl;
}