#include <bits/stdc++.h>
#define sz(S) (int)S.size()
#define debug(a) cerr << #a << " = " << a << endl;
#define vi vector<int>
#define all(S) begin(S),end(S)
#define ll long long
using namespace std;

string s1,s2;

void rotate(char &c) {
    c = (((c-'A')+1)%6)+'A';
}

string mut(string s, char op, int idx) {
    switch(op) {
        case 'A':
            if(idx>0)
                rotate(s[idx-1]);
            if(idx<7)
                rotate(s[idx+1]);
            break;
        case 'B':
            if(idx>0&&idx<7)
                s[idx+1] = s[idx-1];
            break;
        case 'C':
            rotate(s[7-idx]);
            break;
        case 'D':
            if(idx>3) {
                for(int i=idx+1; i<8; i++)
                    rotate(s[i]);
            } else {
                for(int i=0; i<idx; i++) {
                    rotate(s[i]);
                }
            }
            break;
        case 'E':
            int y;
            if(idx>3) y = 7-idx;
            else y = idx;
            rotate(s[idx-y]);
            rotate(s[idx+y]);
            break;
        case 'F':
            if(idx%2) {
                int pos = ((idx+1)/2)-1;
                rotate(s[pos]);
            } else {
                int pos = (((idx+1)+9)/2)-1;
                rotate(s[pos]);
            }
            break;
    }
    return s;
}

int main() {
    cin>>s1>>s2;

    queue<pair<string,int>> Q;
    unordered_map<string,int> V;
    Q.push({s1,0});
    V[s1]=0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        if(cur.first == s2) break;
        for(int i=0; i<8; i++) {
            string temp = mut(cur.first, cur.first[i],i);
            if(V.count(temp)) {
                if(V[temp] > cur.second+1)
                    Q.push({temp,cur.second+1});
            } else {
                V[temp]=cur.second+1;
                Q.push({temp,cur.second+1});
            }
        }
    }
    cout<<V[s2]<<endl;
}
