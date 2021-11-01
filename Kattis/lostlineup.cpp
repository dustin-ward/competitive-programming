#include <bits/stdc++.h>
using namespace std;

int main() {
   int n; cin>>n;

   vector<pair<int,int>> v;
   for(int i=0; i<n-1; i++) {
      int temp; cin>>temp;
      v.push_back(make_pair(temp, i+2));
   }

   sort(v.begin(), v.end());

   cout<<1<<" ";
   for(int i=0; i<n-1; i++)
      cout<<v[i].second<<" ";
   cout<<endl;
}