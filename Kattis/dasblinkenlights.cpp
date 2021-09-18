#include<iostream>
using namespace std;

int gcd(int a, int b){
  if(a==b)
    return a;
  else if(a>b)
    return gcd(a-b, b);
  else
    return gcd(a, b-a);
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}


int main(){
  int p,q,s;
  cin>>p>>q>>s;

  int mult = lcm(p,q);

  if(mult<=s)
    cout<<"yes"<<endl;
  else
    cout<<"no"<<endl;
}