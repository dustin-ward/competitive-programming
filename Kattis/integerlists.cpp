#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        string p; cin>>p;
        int n; cin>>n;
        char c;

        deque<int> x;
        cin>>c;
        for(int i=0; i<n; i++) {
            if(i) cin>>c;
            int temp;
            cin>>temp;
            x.push_back(temp);
        }
        cin>>c;

        bool error = false;
        bool r = false;
        for(int i=0; i<p.length(); i++) {
            if(p[i] == 'R') {
                r = !r;
            }
            else if(p[i] == 'D') {
                if(x.size() == 0) {
                    error = true;
                    break;
                }
                else {
                    if(r)
                        x.pop_back();
                    else
                        x.pop_front();
                }
            }
        }

        if(r && x.size() > 1)
            reverse(x.begin(), x.end());

        if(error)
            cout<<"error"<<endl;
        else {
            cout<<"[";
            for(int i=0; i<x.size(); i++) {
                cout<<x[i];
                if(i < x.size()-1)
                    cout<<",";
            }
            cout<<"]"<<endl;
        }
    }
}