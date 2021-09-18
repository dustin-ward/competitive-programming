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
   int L, D, X, N, M=0;
   cin>>L>>D>>X;

   N=D+1;
   for(int i=L; i<=D; i++){
      int sum = findSum(i);

      if(sum == X){
     if(i > M)
        M = i;
     if(i < N)
        N = i;
      }

   }

   cout<<N<<endl;
   cout<<M<<endl;

}