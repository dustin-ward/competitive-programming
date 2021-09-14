#include <bits/stdc++.h>
using namespace std;

set<long long> ans;

void f(long long lo, long long hi, long long count) {
    if(hi < lo) return;
    cout<<"q "<<lo<<" "<<hi<<endl;
    cout<<flush;
    long long res; cin>>res;
    if(!res)
        return;
    if(hi-lo <= 2) {        // lo == (hi/2)+1
        for(int i=lo; i<=hi; i++) {
            cout<<"q "<<i<<" "<<i<<endl;
            cout<<flush;
            long long res2; cin>>res2;
            if(res2) {
                ans.insert(i);
            }
        }
        return;
    }
    // cout<<"first recurse "<<lo<<" "<<hi/2<<endl;
    f(lo, (lo+hi)/2);
    // cout<<"second recurse "<<(hi/2)+1<<" "<<hi<<endl;
    f(((lo+hi)/2)+1, hi);
}

int main() {
    long long lo=0, hi=9223372036854775807;
    f(lo, hi);

    cout<<"a "<<ans.size()<<" ";
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
}   