#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    char c;
    while(cin>>n && n) {
        cin>>c;
        vector<int> p(n), inp(n);
        for(int i=0; i<n; i++) {
            cin>>p[i];
            inp[p[i]] = i;
        }

        bool flag = false;
        for(int i=0; i<n && !flag; i++) {
            for(int j=1; p[i]+2*j<n; j++) {
                if((inp[p[i]+j] > i && (inp[p[i]+2*j] > inp[p[i]+j]))
                    || (inp[p[i]+j] < i && inp[p[i]+2*j] < inp[p[i]+j])) {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
}