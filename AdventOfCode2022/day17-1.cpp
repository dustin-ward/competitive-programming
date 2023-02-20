#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

const double PI = acos(-1);
double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

vector<vector<char>> B;

vpii SHAPES[5] = {
    {{0,2},{0,3},{0,4},{0,5}},
    {{0,3},{1,2},{1,3},{1,4},{2,3}},
    {{0,2},{0,3},{0,4},{1,4},{2,4}},
    {{0,2},{1,2},{2,2},{3,2}},
    {{0,2},{0,3},{1,2},{1,3}}
};

void Print() {
    for(int i=sz(B)-1; i>=0; --i) {
        for(char j:B[i])
            cout<<j;
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    B.resize(3, vector<char>(7,'.'));
    string s; cin>>s;

    int sPos = 0;
    for(int shape=1; shape<=2022; ++shape) {
        vpii shp = SHAPES[(shape-1)%5];

        int maxHeight = 0;
        for(int i=sz(B)-1; i>=0; --i) {
            for(char j:B[i]) {
                if(j=='#') {
                    maxHeight = max(maxHeight, i+1);
                    break;
                }
            }
        }

        if(maxHeight >= sz(B)-8)
            for(int i=0; i<4; ++i)
                B.push_back(vector<char>(7,'.'));

        for(pii &p:shp)
            p.fst += maxHeight + 3;

        while(1) {
            bool canMove = true;
            if(s[sPos] == '<') {
                for(auto &p:shp) {
                    if(p.snd == 0)
                        canMove = false;
                    else if(B[p.fst][p.snd-1] != '.')
                        canMove = false;
                }
                if(canMove)
                    for(auto &p:shp)
                        p.snd--;
            } else {
                for(auto &p:shp) {
                    if(p.snd == 6)
                        canMove = false;
                    else if(B[p.fst][p.snd+1] != '.')
                        canMove = false;
                }
                if(canMove)
                    for(auto &p:shp)
                        p.snd++;
            }

            sPos = (sPos+1)%sz(s);

            canMove = true;
            for(auto &p:shp) {
                if(p.fst == 0 || B[p.fst-1][p.snd] != '.') {
                    canMove = false;
                    break;
                }
            }
            if(!canMove)
                break;

            for(auto &p:shp)
                p.fst--;
            
        for(auto p:shp)
            B[p.fst][p.snd] = '#';
    }
    int ans = 0;
    for(int i=sz(B)-1; i>=0; --i) {
        for(char j:B[i]) {
            if(j == '#') {
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
}
