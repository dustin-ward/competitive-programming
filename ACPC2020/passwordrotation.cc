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
template<typename T>
T bpow(T x, ll n, T m) { return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : T(1); }
ll inv(ll x, ll p) {
  return bpow(x, p-2, p); 
}

vector<ll> P = {
  999996227,
  999999733,
  // 999999193,
};

vector<ll> B = {
  1009,
  1009,
  // 1009,
};

vector<ll> I = {
  inv(B[0], P[0]),
  inv(B[1], P[1]),
  // inv(B[2], P[2]),
};


ll h(const string& s, int x) {
  int n = sz(s); ll hs = 0;
  for (int i = 0; i < n; i++) {
    hs += (ll(s[i]) * bpow(B[x], i, P[x])) % P[x];
    hs %= P[x];
  }
  return hs;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;

  vector<unordered_set<ll>> H(3);

  auto check = [&] (const string& s) {
    int m = sz(s);
    string t = s + s;
    vector<ll> hs(sz(P));
    for (int p = 0; p < sz(P); p++) hs[p] = h(s, p);

    for (int i = 0; i < m; i++) {
      for (int p = 0; p < sz(P); p++) {
        ll& x = hs[p];
        x = (P[p] + x - ll(t[i]));
        x %= P[p];
        x = (x + (ll(t[i+m]) * bpow(B[p], m, P[p])) % P[p]);
        x %= P[p];
        x = (x * I[p]);
        x %= P[p];
      }
      
      if (H[0].count(hs[0]) 
      and H[1].count(hs[1]) 
      // and H[2].count(hs[2])
      ) {
        return true;
      }
    }

    return false;
  };

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    if (check(s)) {
      cout << "Yes" << endl; return 0;
    }

    reverse(all(s));
    if (check(s)) {
      cout << "Yes" << endl; return 0;
    }

    for (int p = 0; p < sz(P); p++) {
      H[p].insert(h(s, p));
    }
  }

  cout << "No" << endl;
}

