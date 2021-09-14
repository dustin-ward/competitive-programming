#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> v(n);
    map<int,int> m;

    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        v[i] = temp;
        m[temp]++;
    }

    int remove=0;
    for(int i=0; i<n; i++) {
        bool flag = false;
        for(int j=0; j<=30; j++) {
            auto it = m.find(pow(2,j)-v[i]);
            if(it != m.end()) {
                if(m[pow(2,j)-v[i]] > 1 || (m[pow(2,j)-v[i]] == 1 && pow(2,j)-v[i] != v[i])) {
                    flag = true;
                    break;
                }
            }
        }
        if(!flag)
            remove++;
    }

    cout<<remove<<endl;
}