#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<long long> totals(N, 0);
        for(int i=0; i<N; i++) {
            int W; cin>>W;
            for(int j=0; j<W; j++) {
                long long temp; cin>>temp;
                totals[i] += temp;
            }

        }
        sort(totals.begin(), totals.end());
        long long ans=0, prevWait=0;
        for(int i=0; i<totals.size(); i++) {
            long long waitTime = prevWait + totals[i];
            ans += waitTime;
            prevWait = waitTime;
        }
        cout<<fixed<<setprecision(16)<<(double)ans / (double)N<<endl;
    }
}