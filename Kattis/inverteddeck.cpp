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

int main() {
  int N; cin>>N;
  vi V(N);
  for(int &i:V)
    cin>>i;

  vector<pii> R;
  int i=0;
  bool tracking = false;
  while(i<N-1) {
    if(tracking) {
      if(V[i+1] > V[i]) {
        R[sz(R)-1].snd = i+1;
        tracking = false;
      }
    }
    else {
      if(V[i+1] < V[i]) {
        R.emplace_back(i+1,-1);
        tracking = true;
      }
    }
    i++;
  }
  if(tracking)
    R[sz(R)-1].snd = i+1;

  if(sz(R) > 1) {
    cout<<"impossible"<<endl;
    return 0;
  }
  if(!sz(R)) {
    cout<<"1 1"<<endl;
    return 0;
  }

  while(R[0].fst > 1) {
    if(V[R[0].fst-2] != V[R[0].fst-1])
      break;
    R[0].fst--;
  }

  debug(R);

  reverse(V.begin()+R[0].fst-1, V.begin()+R[0].snd);
  debug(V);
  
  for(int i=0; i<N-1; ++i) {
    if(V[i+1] < V[i]) {
      cout<<"impossible"<<endl;
      return 0;
    }
  }

  cout<<R[0].fst<<" "<<R[0].snd<<endl;
}
