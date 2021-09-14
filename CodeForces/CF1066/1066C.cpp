#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(200001);

    int q; cin>>q;
    int l=0, r=1;
    for(int i=0; i<q; i++) {
        char c; cin>>c;
        int idx; cin>>idx;

        switch(c) {
            case 'L':
                v[idx] = l--;
                break;
            case 'R':
                v[idx] = r++;
                break;
            case '?':
                int left = v[idx] - l;
                int right = r - v[idx];
                cout<<min(left, right)-1<<endl;
                break;
        }
    }

    
}