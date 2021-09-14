#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int even=0, odd=0;
        for(int i=0; i<n; i++) {
            int temp; cin>>temp;
            if(temp%2 != i%2) {
                if(i%2) 
                    odd++;
                else 
                    even++;
            }
        }

        if(even == odd)
            cout<<even<<endl;
        else
            cout<<-1<<endl;
    }
}