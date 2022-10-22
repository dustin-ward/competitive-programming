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

int N,M;
vi X;

int dp[302][302][302][2] = {-1};

int f(int l, int r, int k, int pos) {
	cout<<"l "<<l<<" r "<<r<<" k "<<k<<" pos "<<pos<<endl;
	if(!k) return 0;

	int &ans = dp[l][r][k][pos];
	//debug(dp[l][r][k][pos]);
	//if(ans != -1) return ans;

	int curPos = (pos)?r:l;

	int lAns=-1,rAns=-1;
	if(l > 0)
		lAns = f(l-1, r, k-1, 0) + abs(X[l-1]-X[curPos]);
	if(r < N-1)
		rAns = f(l, r+1, k-1, 1) + abs(X[r+1]-X[curPos]);
	cout<<"lAns "<<lAns<<" rAns "<<rAns<<endl;

	if(lAns == -1 && rAns == -1) return 0;
	
	if(lAns == -1) return ans = rAns;
	if(rAns == -1) return ans = lAns;
	return ans = min(lAns,rAns);
}

int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<N; ++j)
			for(int k=0; k<N; ++k)
				dp[i][j][k][0] = dp[i][j][k][1] = -1;

	X.resize(N);
	int zero = 0;
	for(int &i:X) {
		cin>>i;
		if(i == 0)
			zero = M;
	}
	debug(zero);
	if(zero == 0) {
		X.push_back(0);
		N++;
	}
	sort(all(X));
	debug(X);
	int zero_pos = distance(X.begin(), lower_bound(all(X), 0));

	int ans = 0;
	for(int k=1; k<N; ++k) {
		debug(k);
		int val = f(zero_pos, zero_pos, k, 0);
		debug(val);
		ans = max(k*M - val, ans);
		debug(k*M - val);
	}
	cout<<ans+zero<<endl;
}
