// ***Conquest Campaign Solution***
// Difficulty: 2.1
// Time Limit: 1 second, Memory Limit: 1024 MB
// Acceptance: 48%
// CPU Time: 0.02 s
// Author: No author
// Source: The 2018 ICPC Asia Hanoi Regional Contest
// Link: https://open.kattis.com/problems/conquestcampaign


#include <bits/stdc++.h>
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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int R,C,N;

bool bounds(int i, int j) {
  return i >= 0 && i < R && j >= 0 && j < C;
}

int main() {
  cin>>R>>C>>N;

  vector<vi> b1(R, vi(C,0)), b2(R, vi(C, 0));
  for(int i=0; i<N; ++i) {
    int x,y; cin>>x>>y;
    x--; y--;
    b1[x][y] = b2[x][y] = 1;
  }

  int d = 0;
  bool placed = true;
  while(placed) {
    placed = false;

    for(int i=0; i<R; ++i) {
      for(int j=0; j<C; ++j) {
        if(b1[i][j]) {
          for(int k=0; k<4; ++k) {
            int i2 = i + dy[k];
            int j2 = j + dx[k];
            if(bounds(i2,j2) && !b2[i2][j2]) {
              b2[i2][j2] = 1;
              placed = 1;
            }  
          }
        }
      }
    }

    b1 = b2;
    d++;
  }

  cout<<d<<endl;
}

