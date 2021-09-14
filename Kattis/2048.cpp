#include <bits/stdc++.h>
using namespace std;

// 0 = left/up, 1 = right/down
vector<int> flatten(vector<int> v, int dir) {
    if(dir) {
        for(int i=3; i>0; i--) {
            if(v[i]) {
                for(int j=i-1; j>=0; j--) {
                    if(v[j] == v[i]) {
                        v[i] *= 2;
                        v[j] = 0;
                        break;
                    }
                    else if(v[j]) {
                        break;
                    }
                }
            }
            else {
                for(int j=i-1; j>=0; j--) {
                    if(v[j]) {
                        swap(v[j], v[i]);
                        i++;
                        break;
                    }
                }
            }
        }
    }
    else {
        for(int i=0; i<3; i++) {
            if(v[i]) {
                for(int j=i+1; j<4; j++) {
                    if(v[j] == v[i]) {
                        v[i] *= 2;
                        v[j] = 0;
                        break;
                    }
                    else if(v[j]) {
                        break;
                    }
                }
            }
            else {
                for(int j=i+1; j<4; j++) {
                    if(v[j]) {
                        swap(v[j], v[i]);
                        i--;
                        break;
                    }
                }
            }
        }
    }
    return v;
}

int main() {
    vector<vector<int>> board(4, vector<int>(4));
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cin>>board[i][j];
        }
    }

    int dir; cin>>dir;

    if(dir == 0) { //left
        for(int i=0; i<4; i++)
            board[i] = flatten(board[i], 0);
    }
    else if(dir == 1) { //up
        for(int i=0; i<4; i++) {
            vector<int> v(4);
            for(int j=0; j<4; j++) {
                v[j] = board[j][i];
            }
            v = flatten(v, 0);
            for(int j=0; j<4; j++) {
                board[j][i] = v[j];
            }
        }
    }
    else if(dir == 2) { //right
        for(int i=0; i<4; i++)
            board[i] = flatten(board[i], 1);
    }
    else { //if dir == 3  down
        for(int i=0; i<4; i++) {
            vector<int> v(4);
            for(int j=0; j<4; j++) {
                v[j] = board[j][i];
            }
            v = flatten(v, 1);
            for(int j=0; j<4; j++) {
                board[j][i] = v[j];
            }
        }
    }

    // vector<int> v = {2, 0, 4, 2};
    // v = flatten(v, 1);
    // for(int i:v)
    //     cout<<i<<" ";
    // cout<<endl;

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}