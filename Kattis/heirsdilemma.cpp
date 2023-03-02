#include <bits/stdc++.h>
#define sz(S) (int)S.size()
using namespace std;

int main() {
    int L,H; cin>>L>>H;

    int ans = 0;
    for(int i=L; i<=H; i++) {
        string temp = to_string(i);
        set<char> S;
        bool dup = false;
        for(char c:temp) {
            if(c == '0') dup = true;
            if(S.count(c)) dup = true;
            if(dup) break;
            S.insert(c);
        }
        if(dup) continue;
        
        bool divi = true;
        for(int j=0; j<6; j++) {
            if(i % (temp[j]-'0')) {
                divi = false;
                break;
            }
        }
        if(divi) ans++;
    }
    cout<<ans<<endl;;
}
