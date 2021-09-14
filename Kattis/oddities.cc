#include<iostream>
using namespace std;

int main(){
    int x;
    cin>>x;
    for(int i=0; i<x; i++){
      int y;
      cin>>y;
      if(y%2==0)
          cout<<y<<" is even"<<endl;
      else
          cout<<y<<" is odd"<<endl;

    }
}
