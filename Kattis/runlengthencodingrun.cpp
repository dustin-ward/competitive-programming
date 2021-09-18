#include<iostream>
#include<vector>
using namespace std;


int main(){
  char inst;
  string initMessage;
  vector<char> message;
  cin>>inst>>initMessage;
  
  if(inst=='E'){
    int count;

    for(int i=0; i<initMessage.length(); i++){
      int charCount=0;
      while(initMessage[i]==initMessage[i+1] && i<initMessage.length()-1){
    charCount++;
    i++;
      }
      
      message.push_back(initMessage[i]);
      message.push_back((char)charCount+49);
    }
  }else{
    for(int i=0; i<initMessage.length()-1; i+=2){
      for(int j=0; j<((int)initMessage[i+1]-48); j++){
    message.push_back(initMessage[i]);
      }
    }
  }
  
  for(int i=0; i<message.size(); i++){
    cout<<message[i];
  }
  cout<<endl;

}