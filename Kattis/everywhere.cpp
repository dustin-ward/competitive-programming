#include <bits/stdc++.h>
using namespace std;

int main() {
    int T,N;
    cin>>T;

    for(int i=0; i<T; i++) {
        cin>>N;
        map<string, int> m;
        
        for(int j=0; j<N; j++) {
            string temp;
            cin>>temp;
            m[temp]++;
        }

        cout<<m.size()<<endl;
    }
    
}