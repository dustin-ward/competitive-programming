#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum(ll n) {
   return (n*(n-1))/2;
}

int main() {
   ll n, d;
   cin>>n>>d;
   map<ll, ll> m;
   
   for(ll i=0; i<n; i++) {
      ll temp;
      cin>>temp;
      temp = temp/d;
      m[temp]++;
   }

   ll ans=0;
   for(auto i:m){
      ans += sum(i.second);
   }

   cout<<ans<<endl;

}