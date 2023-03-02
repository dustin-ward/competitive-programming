#include <bits/stdc++.h>
#define sz(S) (int)S.size()
#define debug(a) cerr << #a << " = " << a << endl;
using namespace std;

int main() {
    int N; cin>>N;
    string s1,s2;
    cin>>s1>>s2;

    int same = 0;
    for(int i=0; i<sz(s1); i++) {
        if(s1[i] == s2[i])
            same++;
    }
    int dif = sz(s1)-same;

    int right = min(same,N);
    right += dif-(N-right);

    cout<<right<<endl;
}
