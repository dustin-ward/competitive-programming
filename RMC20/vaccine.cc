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

typedef long double ld;
#define double ld

void f(vector<int>& v, vector<int>& s, int n) {
  int vs = 0, cs = 0;
  for (int i = 0; i < n; i++) {
    if (v[i]) vs += s[i];
    else cs += s[i];
  }

  int nv = accumulate(all(v), 0);
  int nc = n - nv;
  double p1 = double(cs) / double(nc);
  double p2 = double(vs) / double(nv);

  // debug(mp(nc, nv));
  // debug(mp(cs, vs));
  // debug(mp(p1, p2));

  if (cs * nv < vs * nc) cout << "Not Effective" << endl;
  else {
    double ans = 100*(1.0 - p2 / p1);
    cout << fixed << setprecision(9) << ans << endl;
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> v(n), a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    v[i] = (s[0] == 'Y');
    a[i] = (s[1] == 'Y');
    b[i] = (s[2] == 'Y');
    c[i] = (s[3] == 'Y');
  }

  f(v, a, n);
  f(v, b, n);
  f(v, c, n);
}

