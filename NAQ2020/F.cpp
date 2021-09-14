#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++) {
        string line;
        getline(cin, line, '\n');
        // cout<<"F "<<line.substr(0,10)<<"\""<<endl;
        // cout<<"S "<<line.substr(11)<<"\""<<endl;
        if(line.length() >= 10 && line.substr(0, 10) == "Simon says") {
            cout<<line.substr(11)<<endl;
        }
    }
}