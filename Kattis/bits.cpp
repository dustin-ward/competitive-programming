#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        string X; cin>>X;
        int ans = 0;
        for(int i=0; i<X.length(); i++) {
            string s = bitset<32>(stoi(X.substr(0,i+1))).to_string();
            int temp = 0;
            for(char c:s)
                temp += (c == '1');
            ans = max(ans, temp);
        }
        cout<<ans<<endl;
    }
}