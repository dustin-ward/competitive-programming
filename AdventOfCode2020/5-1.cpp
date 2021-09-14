#include <bits/stdc++.h>
using namespace std;

int seats[1032];

int main() {
    string s;
    while(cin>>s) {
        int lo=0, hi=127;
        int midR;
        for(int i=0; i<7; i++) {
            midR = (lo+hi)/2;
            if(s[i] == 'F') {
                hi=midR;
            }
            else {
                lo=midR+1;
            }
        }
        if(lo==hi) midR = lo; 

        lo=0, hi=7;
        int midC;
        for(int i=0; i<3; i++) {
            midC = (lo+hi)/2;
            if(s[7+i] == 'L') {
                hi=midC;
            }
            else {
                lo=midC+1;
            }
        }
        if(lo==hi) midC = lo; 

        seats[(midR*8)+midC] = 1;
    }
    bool flag = false;
    for(int i=0; i<1032; i++) {
        if(seats[i]) {
            flag = true;
        }
        else {
            if(flag) {
                cout<<"ANS: "<<i<<endl;
                break;
            }
        }
    }
}