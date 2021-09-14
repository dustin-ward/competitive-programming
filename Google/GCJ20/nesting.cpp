#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    int caseno=1;
    while(T--) {
        string S; cin>>S;
        S.append("0");
        int maxNum=1;

        bool open=false;
        vector<int> opening(S.length(), 0);
        vector<int> closing(S.length(), 0);
        for(int i=0; i<maxNum; i++) {
            for(int j=0; j<S.length(); j++) {
                if(!i && S[j]-'0' > maxNum)
                    maxNum = S[j]-'0';

                // if(S[j] == '(' || S[j] == ')')
                //     continue;

                if(!open && S[j]-'0' > i) {
                    opening[j]++;
                    open = true;
                }

                if(open && S[j]-'0' <= i) {
                    closing[j]++;
                    open = false;
                }

            }
        }
        // for(int i:opening)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(int i:closing)
        //     cout<<i<<" ";
        // cout<<endl;

        int inc=0;
        for(int i=0; i<max(opening.size(), closing.size()); i++) {
            if(i < opening.size()) {
                for(int j=0; j<opening[i]; j++) {
                    S.insert(i+inc, "(");
                }
                inc += opening[i];
            }
            if(i < closing.size() && i) {
                for(int j=0; j<closing[i]; j++) {
                    S.insert(i+inc, ")");
                }
                inc += closing[i];
            }
        }

        S.erase(S.length()-1, 1);

        cout<<"Case #"<<caseno++<<": "<<S<<endl;
    }
}