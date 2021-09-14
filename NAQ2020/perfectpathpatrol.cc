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

typedef long long ll;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;
  vector<vector<pair<int, ll>>> A(n);
  for (int i = 0, a, b, c; i < n-1; i++) {
    cin >> a >> b >> c;
    A[a].push_back({b, c});
    A[b].push_back({a, c});
  }
  
  vector<int> D(n);
  for (int i = 0; i < n; i++) {
    D[i] = sz(A[i]);
  }

  queue<int> Q;
  for (int i = 0; i < n; i++) {
    if (D[i] == 1) {
      Q.push(i);
    }
  }

  // paths
  long long ans = 0;
  vector<ll> P(n), V(n);
  while (!Q.empty()) {
    int v = Q.front(); Q.pop();
    if (V[v]) continue;
    V[v] = 1;

    int flag = 1;
    vector<ll> X;
    for (auto& a : A[v]) {
      if (V[a.fst]) {
        X.push_back(P[a.fst]);
      } else {
        // parent
        flag = 0;
        D[a.fst]--;
        P[v] = a.snd;
        if (D[a.fst] == 1) Q.push(a.fst);
      }
    }

    if (flag) P[v] = 0;

    int i = 0;
    sort(all(X));
    long long total = accumulate(all(X), 0ll);

    // debug(v);
    // debug(X);
    // debug(ans);
    // debug(total);

    while (total > P[v]) {
      if (i + 1 < sz(X)) {
        if (total - 2*X[i] >= P[v]) {
          total -= 2*X[i];
          ans += X[i];

          X[i+1] -= X[i];
          X[i] = 0;
          i += 1;

        } else {
          long long rem = total - P[v];
          total -= rem;
          ans += (rem + 1) / 2;

          X[i+1] -= rem / 2;
          X[i] -= rem / 2 + (rem % 2);

          assert(total <= P[v]);
        }
      } else {
        assert(total == X[i]);
        if (total > P[v]) {
          long long rem = total - P[v];
          total -= total - P[v];
          ans += rem;

          X[i] -= rem;

          assert(total <= P[v]);
        } else {
          
          assert(total <= P[v]);
        }
      }
    }

    // debug(X);
    // debug(v);
    // debug(ans);
    // debug(total);
    // cerr << endl;
  }

  // debug(P);
  cout << ans << endl;
}

