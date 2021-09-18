#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans[10] = {1, 2, 6, 4, 0, 0, 0, 0, 0, 0};
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        cout<<ans[N-1]<<endl;
    }
}