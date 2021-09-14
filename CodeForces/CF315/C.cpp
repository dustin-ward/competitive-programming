#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000001;

int reverse(int n) {
    int ans = 0;
    while (n > 0) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int p,q; cin>>p>>q;
    vector<int> pi(MAX, 0);
    vector<int> rub(MAX, 0);
    // int pi[MAX] = {0};
    // int rub[MAX] = {0};
    
    vector<int> seive(MAX, 1);
    // int seive[MAX] = {1};
    for(long long i=2; i<MAX; i++) {
        pi[i] = pi[i-1];
        if(seive[i]) {
            pi[i]++;
            for(long long j=i*i; j<MAX; j+=i) {
                seive[j] = 0;
            }
        }
    }

    for(int i=1; i<MAX; i++) {
        if(i == reverse(i))
            rub[i] = rub[i-1] + 1;
        else
            rub[i] = rub[i-1];
    }

    for(int i=MAX-1; i>= 1; i--) {
        if(q*pi[i] <= p*rub[i]) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"Palindromic tree is better than splay tree"<<endl;
}