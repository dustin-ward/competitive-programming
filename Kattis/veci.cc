#include<iostream>
using namespace std;

int findSum(int n){
  int sum=0;
  while(n!=0){
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}

int main(){
  int x, output=0;
  cin>>x;

  for(int i=x+1; i<999999; i++){
    if(findSum(i)==findSum(x)){
      output = i;
      break;
    }
  }

  cout<<output<<endl;
  return 0;
}
