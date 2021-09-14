#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;

    while(T--) {
        int n, x;
        cin>>n>>x;
        string s;
        cin>>s;

        vector<int> pSum;

        int sumS=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '0')
                sumS++;
            if(s[i] == '1')
                sumS--;
            pSum.push_back(sumS);
        }

        if(sumS == x) {
            cout<<-1<<endl;
            continue;
        }
        
        if((sumS < 0 && x > 0) || (sumS > 0 && x < 0)) {
            cout<<0<<endl;
            continue;
        }

        sort(pSum.begin(), pSum.end());

        while(pSum[0] < x) {
            transform(begin(pSum), end(pSum), begin(pSum), [](int x){return x+1;});
        }

        // int num=0, temp = pSum[pSum.size()-1];
        // for(int i=pSum.size()-1; i>=0; i--) {
        //     if(pSum[i] == temp)
        //         num++;
        //     else
        //         break;
        // }

        int ans = 0;
        while(pSum[pSum.size()-1] >= x) {
            transform(begin(pSum), end(pSum), begin(pSum), [](int x){return x-1;});
            ans++;
        }

        // long long i=0, l=0, sum=0, ans=0;
        // while(l <= n * ((x/sumS)+1)) {
        //     //cout<<"i "<<i<<" l "<<l<<" sum "<<sum<<" ans "<<ans<<endl;
        //     if(sum == x)
        //         ans++;
            
        //     if(s[i] == '1')
        //         sum--;
        //     else
        //         sum++;
            
        //     if(i == s.length()-1)
        //         i = 0;
        //     else
        //         i++;
        //     l++;
        // }
        


        cout<<ans<<endl;
    }

}