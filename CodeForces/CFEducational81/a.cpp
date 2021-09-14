#include <bits/stdc++.h>
using namespace std;

//map<int, int> m;

int main() {
    // m[0] = 6;
    // m[1] = 2;
    // m[2] = 5;
    // m[3] = 5;
    // m[4] = 4;
    // m[5] = 5;
    // m[6] = 6;
    // m[7] = 3;
    // m[8] = 7;
    // m[9] = 6;

    // int arr[100000] = {};

    // for(int i=0; i<100000; i++) {
    //     long long j = 0;
    //     if(i != 0)
    //             j = arr[i-1];

    //     while(true) {
            
            
    //         j++;
    //     }

    // }

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string ans = "";

        if(n % 2 == 0) {
            for(int i=0; i<n/2; i++) {
                ans += '1';
            }
        }
        else {
            ans += '7';
            for(int i=0; i<(n/2)-1; i++) {
                ans += '1';
            }
        }
        cout<<ans<<endl;
    }
}