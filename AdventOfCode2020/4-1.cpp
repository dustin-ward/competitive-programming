#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    while(true) {
        string s;
        // cout<<"new looop"<<endl;
        vector<string> v;
        while(getline(cin, s)) {
            if(s == "") break;
            if(s == "-1") goto stop;
            string temp = "";
            for(auto x:s) {
                if(x == ' ') {
                    v.push_back(temp.substr(0,3));
                    // cout<<"adding "<<temp.substr(0,3)<<endl;
                    temp = "";
                }
                else {
                    temp = temp + x;
                }
            }    
            v.push_back(temp.substr(0,3));
            // cout<<"adding "<<temp.substr(0,3)<<endl;        
        }
        sort(v.begin(), v.end());
        if(v.size() == 8) {
            ans++;
        }
        else if(v.size() == 7) {
            bool foundCID = false;
            for(string i:v) {
                if(i == "cid")
                    foundCID = true;
            }
            if(!foundCID)
                ans++;
        }
        
    }
    stop:
    cout<<"ANS: "<<ans<<endl;
}