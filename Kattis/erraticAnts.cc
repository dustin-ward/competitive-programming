#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    int north=0, east=0, south=0, west=0;
    for(int j=0; j<x; j++){
      char temp;
      cin>>temp;
      switch (temp) {
        case 'N':
          north++;
          break;
        case 'E':
          east++;
          break;
        case 'S':
          south++;
          break;
        case 'W':
          west++;
          break;
      }
    }
    int ans = abs(south-north) + abs(east-west);
    cout<<ans<<endl;
  }
  return 0;
}
