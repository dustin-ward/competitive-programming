#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> m;
    int N,W,H;
    cin>>N>>W>>H;

    for(int i=0; i<N; i++) {
        int temp;
        cin>>temp;
        m.push_back(temp);
    }

    int max = floor(sqrt(pow(W, 2) + pow(H, 2)));

    for(auto i : m) {
        if(i > max)
            cout<<"NE"<<endl;
        else
            cout<<"DA"<<endl;
    }

}