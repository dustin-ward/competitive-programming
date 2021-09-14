#include <bits/stdc++.h>
using namespace std;

string f(string s) {
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '-') {
            s[i] = ' ';
            i--;
        }
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    int n; cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    set<string> s;

    for(int i=0; i<n; i++) {
        string temp;
        getline(cin, temp);
        s.insert(f(temp));
    }

    cout<<s.size()<<endl;

}