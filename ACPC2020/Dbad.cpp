#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<int> D;

bool f(int x) {
  vector<priority_queue<int>> v(x);
  int idx = 0;
  for(int i=0; i<D.size(); i++) {
    if(v[idx].empty())
      v[idx].push(D[i]);
    else if(D[i] > v[idx].top()) {
      v[idx].push(D[i]);
    }

    idx++;
    if(idx >= x-1) {
      idx = 0;
      if(v[x-1].size() == K) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  cin>>N>>K;

  for(int i=0; i<N; i++) {
    int temp; cin>>temp;
    D.push_back(temp);
  }

  sort(D.begin(), D.end());

  int lo = 0, hi = N;
  while(lo != hi-1) {
    int mid = (lo+hi)/2;
    cout<<"mid "<<mid<<endl;
    if(mid == 0) break;
    if(f(mid))
      lo = mid;
    else
      hi = mid;
  }

  cout<<lo<<endl;
}