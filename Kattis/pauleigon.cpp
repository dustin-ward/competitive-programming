#include<bits/stdc++.h>
using namespace std;

int main(){
   int N,P,Q;
   cin>>N>>P>>Q;

   bool paul=true;
   for(int i=N; i<P+Q+1; i+=N){
      paul = !paul;
   }

   if(paul)
      cout<<"paul"<<endl;
   else
      cout<<"opponent"<<endl;
}