#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g1;
vector<vector<int>> g2;
vector<bool> rooms;
deque<int> path;

DFS(int x){
  if(x==-1)
    return;
  rooms[x]=true;
  if(x==g1.size()-1){
    return;
  }
  for(int i=0; i<4; i++){
    if(g1[x][i]-1!=x && !rooms[i]){
      
      DFS(g1[x][i]-1);
    }
  }
}

int main(){
  int n;
  cin>>n;

  vector<vector<int>> g1(n, vector<int>(4));
  vector<vector<int>> g2(n, vector<int>(4));
  vector<bool> rooms(n, false);

  for(int i=0; i<n; i++) {
    for(int j=0; j<4; j++) {
	    int temp;
	    cin>>temp;
	    g1[i][j] = temp-1;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<4; j++) {
	    int temp;
	    cin>>temp;
	    g2[i][j] = temp-1;
    }
  }

  DFS(0);

}
