#include <bits/stdc++.h>
using namespace std;

int main() {
    int W,H,D; cin>>W>>H>>D;
    vector<vector<vector<int>>> v(H, vector<vector<int>>(W, vector<int>(D, 1)));

    // Front
    vector<vector<int>> front(H, vector<int>(W));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            char c; cin>>c;
            if(c == '.') {
                front[i][j] = 0;
                for(int k=0; k<D; k++) {
                    v[i][j][k] = 0;
                }
            }
            else {
                front[i][j] = 1;
            }
        }
    }

    // Right
    vector<vector<int>> right(H, vector<int>(D));
    for(int i=0; i<H; i++) {
        for(int j=0; j<D; j++) {
            char c; cin>>c;
            if(c == '.') {
                right[i][j] = 0;
                for(int k=0; k<W; k++) {
                    v[i][k][j] = 0;
                }
            }
            else {
                right[i][j] = 1;
            }
        }
    }

    // Top
    // vector<vector<int>> top(D, vector<int>(W));
    for(int i=D-1; i>=0; i--) {
        for(int j=0; j<W; j++) {
            char c; cin>>c;
            if(c == '.') {
                // top[D-(i+1)][j] = 0;
                for(int k=0; k<H; k++) {
                    v[k][j][i] = 0;
                }
            }
            else {
                // top[D-(i+1)][j] = 1;
            }
        }
    }

    bool valid = true;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            // cout<<"expected "<<front[i][j]<<endl;
            if(front[i][j]) {
                bool f = false;
                for(int k=0; k<D; k++) {
                    // cout<<"actual "<<v[i][j][k]<<endl;
                    if(v[i][j][k]) {
                        f = true;
                        break;
                    }
                }
                if(!f) {
                    valid = false;
                    break;
                }
            }
        }
        if(!valid)
            break;
    }
    if(valid) {
        for(int i=0; i<H; i++) {
            for(int j=0; j<D; j++) {
                // cout<<"expected "<<right[i][j]<<endl;
                if(right[i][j]) {
                    bool f = false;
                    for(int k=0; k<W; k++) {
                        // cout<<"actual "<<v[i][j][k]<<endl;
                        if(v[i][k][j]) {
                            f = true;
                            break;
                        }
                    }
                    if(!f) {
                        valid = false;
                        break;
                    }
                }
            }
            if(!valid)
                break;
        }
    }

    if(valid) {
        int ans = 0;
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                for(int k=0; k<D; k++) {
                    // cout<<v[i][j][k];
                    ans += v[i][j][k];
                }
                // cout<<endl;
            }
            // cout<<"\n"<<endl;
        }
        cout<<ans<<endl;
    }
    else
        cout<<"invalid"<<endl;
}