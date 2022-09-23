#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define sz(x) (int)(x).size()
#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.first << ", " << x.second << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int N,M;

bool check(int i, int j) {
    return i>=0 && i<N && j>=0 && j<M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> B;
    string line;
    while(getline(cin,line)) {
        B.push_back(line);
    }

    N = B.size();
    M = B[0].size();
    string temp(M, '.');

    ll steps = 0;
    bool moved = true;
    while(moved) {
        vector<string> B2(N, temp);
        moved = false;
        // debug(steps);
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(B[i][j] == '>') {
                    if(check(i, j+1)) {
                        if(B[i][j+1] == '.') {
                            moved = true;
                            B2[i][j+1] = '>';
                            B2[i][j] = '.';
                        }
                        else {
                            B2[i][j] = '>';
                        }
                    }
                    else {
                        if(B[i][0] == '.') {
                            moved = true;
                            B2[i][j] = '.';
                            B2[i][0] = '>';
                        }
                        else {
                            B2[i][j] = '>';
                        }
                    }
                }
                else if(B2[i][j] != '>') {
                    B2[i][j] = B[i][j];
                }
            }
        }
        B = B2;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(B[i][j] == 'v') {
                    if(check(i+1, j)) {
                        if(B[i+1][j] == '.') {
                            moved = true;
                            B2[i+1][j] = 'v';
                            B2[i][j] = '.';
                        }
                        else {
                            B2[i][j] = 'v';
                        }
                    }
                    else {
                        if(B[0][j] == '.') {
                            moved = true;
                            B2[i][j] = '.';
                            B2[0][j] = 'v';
                        }
                        else {
                            B2[i][j] = 'v';
                        }
                    }
                }
                else if(B2[i][j] != 'v') {
                    B2[i][j] = B[i][j];
                }
            }
        }
        B = B2;
        steps++;
    }
    cout<<steps<<endl;
}