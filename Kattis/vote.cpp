#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int winner;
        int winningTotal = 0;
        int totalVotes = 0;
        bool tie = false;
        for(int i=0; i<n; i++) {
            int v; cin>>v;
            if(v > winningTotal) {
                winningTotal = v;
                winner = i;
                tie = false;
            }
            else if(v == winningTotal) 
                tie = true;
            totalVotes += v;
        }
        if(tie)
            cout<<"no winner"<<endl;
        else if(winningTotal > totalVotes/2)
            cout<<"majority winner "<<winner+1<<endl;
        else
            cout<<"minority winner "<<winner+1<<endl;
    }
}