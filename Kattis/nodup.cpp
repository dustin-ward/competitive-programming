#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> s;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while(iss >> word) {
        if(s.find(word) != s.end()) {
            cout<<"no"<<endl;
            return 0;
        }
        else {
            s.insert(word);
        }
    }
    cout<<"yes"<<endl;
}