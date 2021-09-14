#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    int caseno=1;
    while(t--) {
        long long A,B=0;
        string Ns;
        cin>>Ns;

        for(int i=0; i<Ns.length(); i++) {
            if(Ns[i] == '4') {
                B += pow(10, (Ns.length()-i)-1);
            }
        }
        A = stoll(Ns);
        A -= B;
        
        cout<<"Case #"<<caseno++<<": "<<A<<" "<<B<<endl;   
    }
}