#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        int ans = 0;

        int N; cin>>N;
        char curChar = '$';
        for(int i=0; i<N; i++) {
            char c; cin>>c;
            if(c == 'F') continue;
            if(curChar == '$') {
                if(c == 'X' || c == 'O')
                    curChar = c;
            }
            else {
                if(c != curChar) {
                    ans++;
                    curChar = c;
                }
            }
        }

        cout<<"Case #"<<caseno++<<": "<<ans<<endl;
    }
}