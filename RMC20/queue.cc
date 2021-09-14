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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n), nxt(n), prv(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    nxt[i] = i+1;
    prv[i] = i-1;
  }

  auto bounds = [&] (int i) { return 0 <= i and i < n; };

  int first = 0;
  vector<vector<int>> ans;
  while (true) {

    ans.push_back({});
    for (int i = first; bounds(i); i = nxt[i]) {
      int flag = 0;
      if (bounds(prv[i]) and a[prv[i]] > a[i]) flag = 1;
      if (bounds(nxt[i]) and a[nxt[i]] > a[i]) flag = 1;
      if (flag) {
        ans.back().push_back(i);
      }

    }

    for (int i : ans.back()) {
      // nxt[prv[i]] -> nxt[i]
      // prv[nxt[i]] -> prv[i]
      if (bounds(prv[i]))
        nxt[prv[i]] = nxt[i];
      else
        first = nxt[i];

      if (bounds(nxt[i]))
        prv[nxt[i]] = prv[i];
    }

    if (ans.back().empty()) {
      ans.pop_back();
      break;
    }
  }

  cout << sz(ans) << endl;;
  for (int i = 0; i < sz(ans); i++) {
    for (int j : ans[i])
      cout << a[j] << ' ';
    cout << endl;
  }

  for (int i = first; bounds(i); i = nxt[i])
    cout << a[i] << ' ';
  cout << endl;

}

