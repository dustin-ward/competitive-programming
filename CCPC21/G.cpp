#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> grid(10, vector<int>(10));
    vector<vector<char>> board(10, vector<char>(10));
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            char c; cin>>c;
            grid[i][j] = c - '0';
        }
    }
    vector<int> regions(10,0);
    vector<int> rows(10,0);
    vector<int> cols(10,0);

    bool valid = true;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            char c; cin>>c;
            board[i][j] = c;
            if(c == '*') {
                if(++regions[grid[i][j]] > 2) {
                    valid = false;
                    // break;
                }
                if(++rows[j] > 2) {
                    valid = false;
                    // break;
                }
                if(++cols[i] > 2) {
                    valid = false;
                    // break;
                }
            }
        }
    }
    
    for(int i=0; i<10; i++) {
        if(regions[i] != 2 || rows[i] != 2 || cols[i] != 2)
            valid = false;
    }

    if(valid) {
        int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for(int i=0; i<10; i++) {
            for(int j=0; j<10; j++) {
                for(int k=0; k<8; k++) {
                    if(board[i][j] == '*') {
                        if(j+dx[k] >= 0 && j+dx[k] < 10 && i+dy[k] >= 0 && i+dy[k] < 10) {
                            if(board[i+dy[k]][j+dx[k]] == '*') {
                                valid = false;
                                // break;
                            }
                        }
                    }
                }
            }
        }
    }

    if(valid)
        cout<<"valid"<<endl;
    else
        cout<<"invalid"<<endl;
}