#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, k; cin>>s>>k;
    string d = "";

    for(int i=0; i<s.length(); i++) {
        int sLetter = s[i] - 'A';
        int kLetter = k[i] - 'A';

        int c;
        if(i%2==0) {
            c = sLetter - kLetter;
            if(c < 0)
                c += 26;
        }
        else {
            c = sLetter + kLetter;
            if(c >= 26)
                c -= 26;
        }
        c += 'A';
        char temp = c;
        d.append(1, temp);
    }

    cout<<d<<endl;
}