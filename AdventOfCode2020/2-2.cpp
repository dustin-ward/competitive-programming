#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans=0;
    int lo, hi;
    char c, k;
    string s;
    while(cin>>lo>>c>>hi>>k>>c>>s) {
        if((s[lo-1] == k) ^ (s[hi-1] == k))
            ans++;
    }
    cout<<"ANSWER: "<<ans<<endl;
}