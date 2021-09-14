#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    bool running = false;
    int ans = 0;
    int lastTime = 0;
    for(int i=0; i<N; i++) {
        int t; cin>>t;
        if(running) {
            ans += t-lastTime;
            running = false;
        }
        else {
            running = true;
        }

        lastTime = t;
    }

    if(running)
        cout<<"still running"<<endl;
    else
        cout<<ans<<endl;
    
}