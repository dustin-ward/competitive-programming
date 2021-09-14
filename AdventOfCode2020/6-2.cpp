#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans=0;
    while(true) {
        string s;
        map<char, int> m;
        int numPeople = 0;
        while(getline(cin, s)) {
            if(s == "") {
                for(auto i:m) {
                    if(i.second == numPeople)
                        ans++;
                }
                break;
            }
            if(s == "-1") goto done;
            numPeople++;
            for(int i=0; i<s.length(); i++)
                m[s[i]]++;
        }
    }
    done:
    cout<<"ANS: "<<ans<<endl;
}