#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    float min, max;
    for(int i=0; i<k; i++) {
        int r; cin>>r;
        min += r; max += r;
    }
    cout<<(min-(3*(n-k)))/n<<" "<<(max+(3*(n-k)))/n<<endl;
}