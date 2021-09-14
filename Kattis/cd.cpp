#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int N, M;
    cin>>N>>M;
    while(N!=0 && M!=0) {
        vector<ll> v;
        for(int i=0; i<N; i++) {
            ll temp;
            cin>>temp;
            v.push_back(temp);
        }

        int count = 0;
        for(int i=0; i<M; i++) {
            ll temp;
            cin>>temp;
            if(find(v.begin(), v.end(), temp)!=v.end())
                count++;
        }

        cout<<count<<endl;
        cin>>N>>M;
    }
}
