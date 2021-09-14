#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno = 1;
    while(T--) {
        int N; cin>>N;
        int arr[100];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        int ans = 0;
        for(int i=0; i<N-1; i++) {
            auto j = min_element(arr+i, arr+N);
            cout<<"Scanning from "<<*(arr+i)<<" to "<<*(arr+N-1)<<endl;
            cout<<"Min element was "<<*j<<endl;
            cout<<"Size: "<<j-arr<<endl;
            ans += j - arr;
            reverse(arr+i, j+1);
            cout<<"L = ";
            for(int x = 0; x<N; x++) cout<<arr[x]<<" ";
            cout<<endl;
        }
        cout<<"Case #"<<caseno++<<": "<<ans<<endl;
    }
}