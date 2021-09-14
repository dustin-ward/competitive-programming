#include <bits/stdc++.h>
using namespace std;

int main() {
    string n; cin>>n;
    int m; cin>>m;
    m = log10(m);
    // cout<<"M: "<<m<<endl;

    while(m >= n.length())
        n = "0" + n;

    n.insert(n.end()-m, '.');
    // cout<<"N: "<<n<<endl;

    while(n[n.length()-1] == '0')
        n.erase(n.end()-1);

    if(n[n.length()-1] == '.')
        n.erase(n.end()-1);

    cout<<n<<endl;
}