#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> stairs;

    int j=-1;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        if(temp > 1) {
            stairs[j]++;
        }
        else {
            stairs.push_back(1);
            j++;
        }
    }

    cout<<stairs.size()<<endl;
    for(auto i:stairs)
        cout<<i<<" ";
    cout<<endl;

}