#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {for(int i:v) cout<<i<<" "; cout<<endl;}

int fingering[14][10] = {
                            {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, // c
                            {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, // d
                            {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}, // e
                            {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}, // f
                            {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // g
                            {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // a
                            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // b
                            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // C
                            {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}, // D
                            {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}, // E
                            {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}, // F
                            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // G
                            {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // A
                            {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // B
                        };

map<char,int> m = {
                            {'c', 0},
                            {'d', 1},
                            {'e', 2},
                            {'f', 3},
                            {'g', 4},
                            {'a', 5},
                            {'b', 6},
                            {'C', 7},
                            {'D', 8},
                            {'E', 9},
                            {'F', 10},
                            {'G', 11},
                            {'A', 12},
                            {'B', 13},
                   };

int main() {
    int T; cin>>T;
    string garbage; getline(cin, garbage);
    while(T--) {
        string song;
        getline(cin, song);

        vector<int> f(10, 0), ans(10, 0);

        if(song == "") { 
            print(f);
            continue;
        }

        for(char c:song) {
            for(int i=0; i<10; i++) {
                if(f[i] != fingering[m[c]][i]) {
                    if(f[i])
                        f[i] = 0;
                    else {
                        f[i] = 1;
                        ans[i]++;
                    }
                }
            }
        }

        print(ans);
    }
}