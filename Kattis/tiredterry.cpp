#include <bits/stdc++.h>
using namespace std;

int main() {
   int n,p,d; cin>>n>>p>>d;
   string s; cin>>s;
   vector<int> sum(n*2, 0);
   
   s = s + s;

   if(s[0] == 'Z')
      sum[0] = 1;
   for(int i=1; i<n*2; i++) {
      if(s[i] == 'Z')
     sum[i] = sum[i-1]+1;
      else
     sum[i] = sum[i-1];
   }

   int tired=0;
   for(int i=n; i<n*2; i++) {
      if(sum[i]-sum[i-p] < d)
     tired++;
   }

   cout<<tired<<endl;
}