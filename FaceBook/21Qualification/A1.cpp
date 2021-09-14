#include <bits/stdc++.h>
using namespace std;

bool vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    int caseno = 1;
    int T; cin>>T;
    while(T--) {
        string S; cin>>S;
        int minAns = INT_MAX;
        for(int i='A'; i<='Z'; i++) {
            int x = 0;
            for(auto c:S) {
                if(c == i) continue;
                if(vowel((char)i) ^ vowel(c))
                    x++;
                else
                    x += 2;
            }
            minAns = min(minAns, x);
        }
        cout<<"Case #"<<caseno++<<": "<<minAns<<endl;
    }
}