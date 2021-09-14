#include<iostream>
#include<iterator>
#include<list>
using namespace std;

int main(){
  int n;
  cin>>n;

  list<int> l;
  for(int i=0; i<n; i++){
    int in;
    cin>>in;
    l.push_back(in);
  }

  for(list<int>::iterator it=l.begin(); it!=l.end(); it++){
    if((it+it+1)%2==0){
      l.erase(it);
    }
  }

  // int size = l.size();
  // cout<<size<<endl;

}
