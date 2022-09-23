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

double dp[5][5][5][5][9];
int R,G,B,Y,S;

double f(int r, int g, int b, int y, int s) {
  double &prob = dp[r][g][b][y][s];
  if(prob == -1.0) {
    prob = 0.0;
    
    int empty = 0;
    if(!r)
      empty++;
    if(!g)
      empty++;
    if(!b)
      empty++;
    if(!y)
      empty++;

    double p = 1.0/(6-empty);

    prob += p * f(r,g,b,y,s-1);
    if(r)
      prob += p * f(r-1,g,b,y,s);
    if(g)
      prob += p * f(r,g-1,b,y,s);
    if(b)
      prob += p * f(r,g,b-1,y,s);
    if(y)
      prob += p * f(r,g,b,y-1,s);

    if(r >= g && r >= b && r >= y)
      prob += p * f(r-1, g, b, y, s);
    else if(g >= r && g >= b && g >= y)
      prob += p * f(r, g-1, b, y, s);
    else if(b >= r && b >= g && b >= y)
      prob += p * f(r, g, b-1, y, s);
    else
      prob += p * f(r, g, b, y-1, s);
  }

  return prob;
}

int main() {
  fill(&dp[0][0][0][0][0], &dp[0][0][0][0][0]+ sizeof(dp)/sizeof(dp[0][0][0][0][0]), -1.0);
  cin>>R>>G>>B>>Y>>S;
  for(int i=1; i<9; ++i)
    dp[0][0][0][0][i] = 1.0;
  for(int r=0; r<5; ++r)
    for(int g=0; g<5; ++g)
      for(int b=0; b<5; ++b)
        for(int y=0; y<5; ++y)
          dp[r][g][b][y][0] = 0.0;

  cout<<fixed<<setprecision(10)<<f(R,G,B,Y,S)<<endl;
}
