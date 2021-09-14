#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define FOR(s, n) for(int i = s; i < n; ++i)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) {  o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) {  o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int N, K;
vector<int> d;

bool f(int g) {
  vector<pair<int,int>> A(g, {0,0});
  int j = 0;
  for(int i = 0; i < N; ++i) {
    auto& p = A[j];
    if(d[i] > p.first) {
      p.first = d[i];
      ++p.second;
      ++j;

      if(j == g) {
        if(p.second == K) return true;
        j = 0;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  
  d.assign(N, 0);
  for(int& x : d) cin >> x;

  sort(all(d));

  int lower = 0, upper = N/K + 1;
  while(upper-lower > 1) {
    int mid = (upper+lower)/2;
    if(f(mid)) lower = mid;
    else upper = mid;
  }

  cout << lower << endl;
}

