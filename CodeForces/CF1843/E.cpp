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

class FenwickTree
{
public:
  FenwickTree(int n = 0)
    : N(n), tree(n)
  {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }
    tree.resize(iBM+1);
    fill(tree.begin(), tree.end(), 0);
  }

  // initialize the tree with the given array of values
  FenwickTree(int val[], int n)
    : N(n)
  {
    iBM = 1;
    while (iBM < N) {
      iBM *= 2;
    }
    
    tree.resize(iBM+1);
    fill(tree.begin(), tree.end(), 0);
    for (int i = 0; i < n; i++) {
      assert(val[i] >= 0);
      incEntry(i, val[i]);
    }
  }

  // increment the entry at position idx by val (use negative val for
  // decrement).  All affected cumulative sums are updated.
  void incEntry(int idx, int val)
  {
    assert(0 <= idx && idx < N);
    if (idx == 0) {
      tree[idx] += val;
    } else {
      do {
	tree[idx] += val;
	idx += idx & (-idx);
      } while (idx < (int)tree.size());
    }
  }

  // return the cumulative sum val[0] + val[1] + ... + val[idx]
  int cumulativeSum(int idx) const
  {
    assert(0 <= idx && idx < (int)tree.size());
    int sum = tree[0];
    while (idx > 0) {
      sum += tree[idx];
      idx &= idx-1;
    }
    return sum;
  }

  // return the entry indexed by idx
  int getEntry(int idx) const
  {
    assert(0 <= idx && idx < N);
    int val, parent;
    val = tree[idx];
    if (idx > 0) {
      parent = idx & (idx-1);
      idx--;
      while (parent != idx) {
	val -= tree[idx];
	idx &= idx-1;
      }
    }
    return val;
  }

  // return the largest index such that the cumulative frequency is
  // what is given, or -1 if it is not found
  //
  int getIndex(int sum) const
  {
    int orig = sum;
    if (sum < tree[0]) return -1;
    sum -= tree[0];
    
    int idx = 0;
    int bitmask = iBM;

    while (bitmask != 0 && idx < (int)tree.size()-1) {
      int tIdx = idx + bitmask;
      if (sum >= tree[tIdx]) {
	idx = tIdx;
	sum -= tree[tIdx];
      }
      bitmask >>= 1;
    }

    if (sum != 0) {
      return -1;
    }

    idx = min(N-1, idx);
    return (cumulativeSum(idx) == orig) ? idx : -1;
  }
  
private:
  int N, iBM;
  vector<int> tree;
};

int N,M,Q;
vpii P;
vi X;

bool f(FenwickTree &ft) {
	for(auto &[l,r]:P) {
		// debug(l);
		// debug(r);
		// debug(ft.cumulativeSum(l));
		// debug(ft.cumulativeSum(r));
		int sum = ft.cumulativeSum(r);
		if(l>0)
			sum -= ft.cumulativeSum(l-1);
		if(sum > ((r+1)-l)/2)
			return true;
	}
	return false;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>N>>M;
		P.clear();
		for(int i=0; i<M; i++) {
			int l,r; cin>>l>>r;
			P.emplace_back(l-1,r-1);
		}

		cin>>Q;
		X.clear();
		X.resize(Q);
		for(int &i:X) {
			cin>>i;
			i--;
		}

		int lo=0, hi=Q;
		int ftIdx = 0;
		FenwickTree ft(N);
		while(hi-lo > 1) {
			int mid = (lo+hi)/2;
			// debug(mid);
			
			if(mid < ftIdx) {
				// debug("REBUILDING...");
				ft = FenwickTree(N);
				ftIdx = 0;
			}
			while(ftIdx < mid) {
				// debug(X[ftIdx]);
				ft.incEntry(X[ftIdx++], 1);
			}
			// debug(ftIdx);

			if(f(ft)) {
				// debug("T")
				hi = mid;
			} else {
				// debug("F")
				lo = mid;
			}
		}
		if(hi==M)
			cout<<-1<<endl;
		else
			cout<<hi<<endl;
	}
}
