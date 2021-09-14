#include <bits/stdc++.h>
using namespace std;

struct s {
    int val;
    bool swap = false;
};

int main() {
    int c; cin>>c;
    while(c--) {
        int n,m; cin>>n>>m;
        vector<s> a(n, s());
        for(int i=0; i<n; i++) {
            int temp; cin>>temp;
            a[i].val = temp;
        }
        for(int i=0; i<m; i++) {
            int temp; cin>>temp;
            a[temp-1].swap = true;
        }

        bool print = false;
        for(int i=0; i<n-1; i++) {
            bool min = true;
            for(int j=i+1; j<n; j++) {
                if(a[j].val < a[i].val) {
                    min = false;
                    break;
                }
            }
            if(!min && !a[i].swap) {
                cout<<"NO"<<endl;
                print = true;
            }
            else if(!min) {
                int temp = a[i].val; a[i].val = a[i+1].val; a[i+1].val = temp;
            }
        }

        if(!print)
            cout<<"YES"<<endl;
    }
}