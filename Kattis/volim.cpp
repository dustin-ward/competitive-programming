#include<iostream>
using namespace std;


int main(){
   int player, questions, time=0;
   cin>>player>>questions;

   for(int i=0; i<questions; i++){
      int timeTemp;
      char ans;
      cin>>timeTemp>>ans;

      time += timeTemp;
      if(time>=210){
     break;
      }
      
      if(ans == 'T'){
     player++;
     if(player==9)
        player=1;
      }
     
   }

   cout<<player<<endl;
}