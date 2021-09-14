#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin>>s;

    int whitespace=0, uppercase=0, lowercase=0, symbols=0;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '_') whitespace++;
        else if(s[i] < 'A' || (s[i] > 'Z' && s[i] < 'a') || s[i] > 'z') symbols++;
        else if(s[i] >= 'A' && s[i] <= 'Z') uppercase++;
        else if(s[i] >= 'a' && s[i] <= 'z') lowercase++;
    }

    cout<<setprecision(10)<<(double)whitespace/s.length()<<endl;
    cout<<setprecision(10)<<(double)lowercase/s.length()<<endl;
    cout<<setprecision(10)<<(double)uppercase/s.length()<<endl;
    cout<<setprecision(10)<<(double)symbols/s.length()<<endl;
}