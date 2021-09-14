#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, caseno=1; 
    while(cin>>n) {
        vector<int> N(n);
        for(int i=0; i<n; i++)
            cin>>N[i];

        vector<int> sums;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++)
                sums.push_back(N[i] + N[j]);
        }
        sort(sums.begin(), sums.end());

        int m; cin>>m;
        cout<<"Case "<<caseno++<<":"<<endl;
        for(int i=0; i<m; i++) {
            int q; cin>>q;
            auto x1 = lower_bound(sums.begin(), sums.end(), q);
            auto x2 = x1-1;

            if(x1 == sums.begin())
                cout<<"Closest sum to "<<q<<" is "<<(*x1)<<"."<<endl;
            else if(x1 == sums.end() || abs((*x1) - q) > abs((*x2) - q))
                cout<<"Closest sum to "<<q<<" is "<<(*x2)<<"."<<endl;
            else
                cout<<"Closest sum to "<<q<<" is "<<(*x1)<<"."<<endl;
        }
    }
}