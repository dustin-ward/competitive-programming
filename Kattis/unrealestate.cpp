#include <bits/stdc++.h>
#include <iomanip>
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

const double PI = acos(-1);
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

typedef tuple<double,int,int> seg;

// (x1,y1) , (x2,y2) are corners of axis-aligned rectangles
struct rectangle{ double x1,y1,x2,y2; };

struct segment_tree{
  int n; const vector<double>& v;  vector<int> pop;  vector<double> len;
  segment_tree(const vector<double>& y) : n(y.size()),v(y),pop(2*n-3),len(2*n-3) {}

  double add(pair<double,double> s,int a){ return add(s,a,0,n-2); }
  double add(const pair<double,double>& s, int a, int lo, int hi){
    int m = (lo+hi)/2 + (lo == hi ? n-2 : 0);
    if(a && (v[lo] < s.second) && (s.first < v[hi+1])){
      if((s.first <= v[lo]) && (v[hi+1] <= s.second)){
	pop[m] += a;
	len[m] = (lo == hi ? 0 : add(s,0,lo,m) + add(s,0,m+1,hi));
      } else len[m] = add(s,a,lo,m) + add(s,a,m+1,hi);
      if(pop[m] > 0) len[m] = v[hi+1] - v[lo];
    }
    return len[m];
  }
};

double area_union_rectangles(vector<rectangle>& R){
  vector<double> y; vector<seg> v;
  for(int i=0;i<R.size();i++){
    if(R[i].x1 == R[i].x2 || R[i].y1 == R[i].y2) continue;
    y.push_back(R[i].y1), y.push_back(R[i].y2);
    if(R[i].y1 > R[i].y2) swap(R[i].y1,R[i].y2);
    v.push_back(seg(min(R[i].x1,R[i].x2),i, 1));
    v.push_back(seg(max(R[i].x1,R[i].x2),i,-1));
  }
  sort(v.begin(),v.end());  sort(y.begin(),y.end());
  y.resize(unique(y.begin(),y.end()) - y.begin());
  segment_tree s(y); double area = 0, amt = 0, last = 0;
  for(int i=0;i<v.size();i++){
    area += amt * (get<0>(v[i]) - last);
    last = get<0>(v[i]); int t = get<1>(v[i]);
    amt = s.add(make_pair(R[t].y1,R[t].y2),get<2>(v[i]));
  }
  return area;
}

int main() {
    int N; cin>>N;

    vector<rectangle> A(N);
    for(rectangle &r:A)
        cin>>r.x1>>r.y1>>r.x2>>r.y2;

    cout<<fixed<<setprecision(2)<<area_union_rectangles(A)<<endl;
}
