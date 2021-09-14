#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    vector<int> inv(n);
    vector<int> avail(n+1, 1);
    vector<int> used(n+1, 0);
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        inv[i] = temp;
        if(temp <= n)
            avail[temp] = 0;
    }

    int counter = 1;
    for(int i=0; i<n; i++) {
        if(inv[i] > n || used[inv[i]]) {
            while(!avail[counter]) counter++;
            inv[i] = counter;
            avail[counter] = 0;
        }
        used[inv[i]] = 1;
    }

    for(int i=0; i<n; i++)
        cout<<inv[i]<<" ";
    cout<<endl;

}