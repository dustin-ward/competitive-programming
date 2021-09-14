#include <bits/stdc++.h>
using namespace std;

int paths[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

int main() {
    vector<string> map;
    string s;
    long long ans=1;
    while(cin>>s && s != "")
        map.push_back(s);
    
    for(int i=0; i<5; i++) {
        int trees = 0;
        int x=paths[i][0], y=paths[i][1];
        while(y < map.size()) {
            if(map[y][x] == '#')
                trees++;
            x = (x + paths[i][0]) % s.length();
            y = y + paths[i][1];
        }
        ans *= trees;
    }
    
    cout<<"ANSER: "<<ans<<endl;
}