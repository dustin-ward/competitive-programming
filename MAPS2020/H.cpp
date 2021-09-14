#include <bits/stdc++.h>
using namespace std;

int main() {
    int C,N,M; cin>>C>>N>>M;
    vector<int> v;
    for(int i=0; i<N; i++) {
        int temp; cin>>temp;
        v.push_back(temp);
    }

    for(int i=0; i<M; i++) {
        int q; cin>>q;
        int sum=0;
        for(int j=0; j<v.size(); j++) {
            if(v[j]==1 && C > 7) {
                sum+= pow(2, max(0, q-((C/2)/2))+1);
            }
            else {
                sum+= pow(2, max(0, q-((C/2)/v[j])));
            }
        }
        cout<<max(N,sum)<<endl;
    }
}