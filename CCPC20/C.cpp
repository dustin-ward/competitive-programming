#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> m;
    m.insert(make_pair('2', 2));
    m.insert(make_pair('3', 3));
    m.insert(make_pair('4', 4));
    m.insert(make_pair('5', 5));
    m.insert(make_pair('6', 6));
    m.insert(make_pair('7', 7));
    m.insert(make_pair('8', 8));
    m.insert(make_pair('9', 9));
    m.insert(make_pair('T', 10));
    m.insert(make_pair('J', 11));
    m.insert(make_pair('Q', 12));
    m.insert(make_pair('K', 13));
    m.insert(make_pair('A', 14));
    int N; cin>>N;

    while(N--) {
        vector<int> Y;
        vector<int> O;

        for(int i=0; i<26; i++) {
            char temp; cin>>temp;
            O.push_back(m[temp]);
        }
        for(int i=0; i<26; i++) {
            char temp; cin>>temp;
            Y.push_back(m[temp]);
        }
        sort(Y.rbegin(), Y.rend());
        sort(O.rbegin(), O.rend());

        for(auto i:O)
            cout<<i<<" ";
        cout<<endl;

        for(auto i:Y)
            cout<<i<<" ";
        cout<<endl;

        int ans=0;
        for(int i=0; i<26; i++) {
            

        }

    }

}