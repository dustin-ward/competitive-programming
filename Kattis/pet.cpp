#include <bits/stdc++.h>
using namespace std;

int main() {
    int maxScore = 0;
    int maxPos = 0;
    for(int i=0; i<5; i++) {
        int score = 0;
        for(int j=0; j<4; j++) {
            int s; cin>>s;
            score += s;
        }
        if(score > maxScore) {
            maxScore = score;
            maxPos = i;
        }
    }
    cout<<maxPos+1<<" "<<maxScore<<endl;
}