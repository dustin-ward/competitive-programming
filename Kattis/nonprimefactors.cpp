#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long max = 2000001;
    vector<int> primes(max, 1);
    vector<int> factors(max, 1);
    for(int i=2; i<max; i++) {
        if(primes[i]) {
            for(int j=i+i; j<max; j+=i) {
                primes[j] = 0;
            }
        }
        else {
            for(int j=i; j<max; j+=i) {
                factors[j]++;
            }
        }
    }

    int Q; cin>>Q;
    vector<int> n(Q);
    for(int i=0; i<Q; i++)
        cin>>n[i];

    for(int i=0; i<Q; i++)
        cout<<factors[n[i]]<<"\n";
}