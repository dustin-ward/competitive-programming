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

// R D L U
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool bounds(pii p) {
  return p.fst >= 0 && p.fst < 8 && p.snd >= 0 && p.snd < 8;
}

int main() {
  pii pos;
  vector<vector<char>> B(8, vector<char>(8));
  for(int i=0; i<8; ++i) {
    for(int j=0; j<8; ++j) {
      cin>>B[i][j];
      if(B[i][j] == 'T') {
        pos.fst = i;
        pos.snd = j;
      }
    }
  }

  int dir = 0;
  bool err = 0;
  string prog; cin>>prog;
  for(char c:prog) {
    if(err) {
      cout<<"Bug!"<<endl;
      return 0;
    }
    pii nextPos = make_pair(pos.fst + dy[dir], pos.snd + dx[dir]);
    switch(c) {
      case 'R':
        dir = (dir+1)%4;
        break;
      case 'L':
        dir = (dir+3)%4;
        break;
      case 'F':
        if(bounds(nextPos)) {
//          if(B[nextPos.fst][nextPos.snd] == 'D') {
//          cout<<"Diamond!"<<endl;
//            return 0;
//          }
          if(B[nextPos.fst][nextPos.snd] == 'C' || B[nextPos.fst][nextPos.snd] == 'I') {
            err = 1;
            break;
          }
          pos = nextPos;
        }
        else
          err = 1;
        break;
      case 'X':
        if(bounds(nextPos) && B[nextPos.fst][nextPos.snd] == 'I')
          B[nextPos.fst][nextPos.snd] = '.';
        else
          err = 1;
        break;
    }
  }
  if(B[pos.fst][pos.snd] == 'D')
    cout<<"Diamond!"<<endl;
  else
    cout<<"Bug!"<<endl;
}
