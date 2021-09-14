#include <bits/stdc++.h>
using namespace std;

int GetNumberOfDigits (int i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main() {
    int T; cin>>T;
    while(T--) {
        int x; cin>>x;
        int n = GetNumberOfDigits(x)-1;
        vector<int> ans;
        //cout<<"N : "<<n<<endl;
        while(x > 10) {
            //cout<<"x : "<<x<<endl;
            int temp1 = x % (int)pow(10, n--);
            //cout<<"temp1 : "<<temp1<<endl;
            int temp2 = x - temp1;
            //cout<<"temp2 : "<<temp2<<endl;
            ans.push_back(temp2);
            x = temp1;
        }
        if(x>0)
            ans.push_back(x);

        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++) {
            cout<<ans[i];
            if(i<ans.size()-1)
                cout<<" ";
        }
        cout<<endl;
    }
}