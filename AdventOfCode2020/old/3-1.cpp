#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> map;
    string s;
    int ans=0;
    while(cin>>s && s != "")
        map.push_back(s);
    
    int x=3,y=1;
    while(y < map.size()) {
        if(map[y][x] == '#')
            ans++;
        x = (x + 3) % s.length();
        y++;
    }
    cout<<"ANSER: "<<ans<<endl;
}