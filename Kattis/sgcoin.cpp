#include <bits/stdc++.h>
using namespace std;

long long H(long long previousHash, string &transaction, long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

typedef long long ll;
ll e = 1e9+7;
int main() {
    ll n; cin>>n;
    string s = "a";
    ll t1 = (e + (ll(1e9) - ((n * 31 + s[0]) % e) * 7) % e) % e;
    ll t2 = (e + (ll(1e9) - ((H(n, s, t1) * 31 + s[0]) % e) * 7) % e) % e;
    cout<<s<<" "<<t1<<endl;
    cout<<s<<" "<<t2<<endl;
}