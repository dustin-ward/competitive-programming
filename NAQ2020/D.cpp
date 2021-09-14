#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, P; cin>>W>>P;
    vector<int> L(P);
    for(int i=0; i<P; i++) {
        cin>>L[i];
    }
    L.push_back(0);
    L.push_back(W);

    set<int> ans;
    for(int i=0; i<L.size(); i++) {
        for(int j=i; j<L.size(); j++) {
            if(abs(L[i]-L[j]))
                ans.insert(abs(L[i]-L[j]));
        }
    }

    for(auto i:ans) {
        cout<<i<<" ";
    }
    cout<<endl;
}