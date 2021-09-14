#include <bits/stdc++.h>
using namespace std;

int main() {
    string str; cin>>str;
    set<char> s;
    for(auto c:str) {
        if(s.find(c) != s.end()) {
            cout<<0<<endl;
            return 0;
        }
        else
            s.insert(c);
    }
    cout<<1<<endl;
}