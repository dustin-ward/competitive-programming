#include <bits/stdc++.h>
using namespace std;

int ask(const vector<int>& q) {
    cout<<"? "<<q.size()<<" ";
    for(int i:q)
        cout<<i<<" ";
    cout<<endl;
    int temp;
    cin>>temp;
    return temp; 
}

int main() {
    int n; cin>>n;

    vector<vector<int>> ans(n, vector<int>(n));

    vector<int> X(n);
    for(int i=0; i<n; i++) {
        X[i] = ask({i+1});
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            vector<int> a1 = {i+1,j+1};

            int res1 = ask(a1);

            if(res1 == X[i]+X[j]) {
                ans[i][j] = ans[j][i] = 0;
            }
            else {
                ans[i][j] = ans[j][i] = 1;
            }
        }
    }

    cout<<"!"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}