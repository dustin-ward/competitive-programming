#include <bits/stdc++.h>
using namespace std;

int main() {
    int expected[6] = {1, 1, 2, 2, 2, 8};
    int change[6];

    for(int i=0; i<6; i++) {
        int temp;
        cin>>temp;
        change[i] = expected[i] - temp;
    }

    for(int i=0; i<6; i++) {
        cout<<change[i]<<" ";
    }
    cout<<endl;
}