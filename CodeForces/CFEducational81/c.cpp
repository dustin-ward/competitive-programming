#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        string s, t;
        cin>>s>>t;

        set<char> sChar;
        for(int i=0; i<s.length(); i++) {
            sChar.insert(s[i]);
        }

        bool flag = false;
        for(int i=0; i<t.length(); i++) {
            if(auto it = sChar.find(t[i]) == sChar.end()) {
                cout<<-1<<endl;
                flag = true;
                break;
            }
        }
        if(flag)
            continue;

        int i = 0;
        while(true) {
            for()

        }

    }

}