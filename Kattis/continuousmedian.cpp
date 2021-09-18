#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        long long ans = 0;
        priority_queue<int> lo, hi;
        for(int i=0; i<N; i++) {
            // cout<<"LOOP "<<i<<endl;
            int x; cin>>x;
            if(lo.empty() || x <= lo.top())
                lo.push(x);
            else 
                hi.push(-x);

            // cout<<"LO: "<<lo.size()<<" "<<((lo.size()) ? lo.top() : -1)<<endl;
            // cout<<"HI: "<<hi.size()<<" "<<((hi.size()) ? -hi.top() : -1)<<endl;
            while(abs((int)lo.size() - (int)hi.size()) >= 2) {
                if(lo.size() > hi.size()) {
                    int temp = lo.top(); lo.pop();
                    hi.push(-temp);
                }
                else {
                    int temp = -hi.top(); hi.pop();
                    lo.push(temp);
                }
                // cout<<"LO: "<<lo.size()<<" "<<lo.top()<<endl;
                // cout<<"HI: "<<hi.size()<<" "<<hi.top()<<endl;
            }

            if(lo.size() != hi.size())
                ans += (lo.size() > hi.size()) ? lo.top() : -hi.top();
            else
                ans += (lo.top()-hi.top()) / 2;
            // cout<<"TOTAL = "<<ans<<endl;
        }

        cout<<ans<<endl;
    }
}