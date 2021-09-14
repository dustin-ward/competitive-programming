#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v;
        bool odd = false;
        bool even = false;
        for(int i=0; i<n; i++) {
            int temp; cin>>temp;
            v.push_back(temp);
            if(temp%2!=0)
                odd = true;
            else
                even = true;        
        }
        if(odd) {
            if(v.size()%2!=0)
                cout<<"YES"<<endl;
            else if(even)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }

    }
}