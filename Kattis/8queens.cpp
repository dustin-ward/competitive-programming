#include <bits/stdc++.h>
using namespace std;
int row[8];
int col[8];
int diagL[17];
int diagR[17];

int main() {

    int count = 0;
    bool flag = true;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            char c; cin>>c;
            if(c == '*') {
                count++;
                if(row[j] || col[i] || diagL[(j-i)+7] || diagR[j+i])
                    flag = false;

                row[j] = 1;
                col[i] = 1;
                diagL[(j-i)+7] = 1;
                diagR[j+i] = 1;
            }
        }
    }

    if(flag && count == 8)
        cout<<"valid"<<endl;
    else
        cout<<"invalid"<<endl;
}
