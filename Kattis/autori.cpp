#include<iostream>
#include<vector>
using namespace std;

int main(){
  string name;
  cin>>name;

  vector<char> initials;
  initials.push_back(name[0]);
  
  for(int i=0; i<name.length()-1; i++){
     if(name[i]=='-'){
    initials.push_back(name[i+1]);
     }
  }

  for (int i=0; i<initials.size(); i++){
     cout<<initials[i];
  }
  
  cout<<endl;
  
}