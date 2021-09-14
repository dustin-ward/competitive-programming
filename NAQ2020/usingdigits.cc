#include <bits/stdc++.h>
using namespace std;

#define debug(a) cerr << #a << " = " << (a) << endl;
#define fst first
#define snd second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair(x, y)
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

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
double time() { return double(clock()) / CLOCKS_PER_SEC; }

const int inf = 1 << 30;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int x, y; cin >> y >> x;
  string s; cin >> s;
  vector<int> k;
  for (auto c : s) k.push_back(c - '0');
  vector<vector<int>> a(x, vector<int>(y));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      char z; cin >> z;
      a[x-i-1][j] = z - '0';
    }
  }

  for (int i = 0; i < x; i++) debug(a[i]);
  vector<vector<vector<int>>> dp(x, vector<vector<int>>(y, vector<int>(sz(k)+1, -1)));
  function<int(int, int, int)> f = [&] (int i, int j, int pos) {
    debug(mp(i, j));

    if (i >= x or j >= y) return inf;
    if (i == x-1 and j == y-1) {
      return 0;
    }

    auto& z = dp[i][j][pos];
    if (z != -1) return z;

    z = inf;
    if (i+1 < x) z = min(z, a[i+1][j] + f(i+1, j, pos));
    if (j+1 < y) z = min(z, a[i][j+1] + f(i, j+1, pos));
    if (pos < sz(k) and i + 1 + k[pos] < x) min(z, a[i+1+k[pos]][j] + f(i+1+k[pos], j, pos+1));
    if (pos < sz(k) and j + 1 + k[pos] < y) min(z, a[i][j+1+k[pos]] + f(i, j+1+k[pos], pos+1));

    debug(mp(i, j));
    debug(z);
    cerr << endl;

    return z + a[i][j];
  };

  cout << a[0][0] + f(0, 0, 0) << endl;
  for (int i = 0; i < x; i++) debug(dp[i]);
}

