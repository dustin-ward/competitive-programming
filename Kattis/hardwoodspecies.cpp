#include <bits/stdc++.h>
using namespace std;

int main() {
    float total = 0;
    map<string,int> m;
    string temp;
    while(getline(cin, temp)) {
        m[temp]++;
        total++;
    }

    for(auto i:m)
        cout<<i.first<<" "<<fixed<<setprecision(10)<<(i.second*100)/total<<endl;
}