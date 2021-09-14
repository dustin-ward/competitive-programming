#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        int N; cin>>N;
        vector<char> ans(N);
        vector<tuple<int,int,int>> v;

        for(int i=0; i<N; i++) {
            int t1, t2; cin>>t1>>t2;
            v.push_back(make_tuple(t1,t2,i));
        }

        sort(v.begin(), v.end());

        int cTime=0, jTime=0;
        bool imp=false;
        for(int i=0; i<N; i++) {
            if(cTime <= get<0>(v[i])) {
                ans[get<2>(v[i])] = 'C';
                cTime = get<1>(v[i]);
            }
            else if(jTime <= get<0>(v[i])) {
                ans[get<2>(v[i])] = 'J';
                jTime = get<1>(v[i]);
            }
            else {
                imp = true;
                break;
            }
        }

        if(imp) {
            cout<<"Case #"<<caseno++<<": IMPOSSIBLE"<<endl;
        }
        else {
            cout<<"Case #"<<caseno++<<": ";
            for(auto i:ans)
                cout<<i;
            cout<<endl;
        }
    }
}