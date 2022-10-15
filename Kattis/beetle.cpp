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

int dpl[302][302][302] = {-1};
int dpr[302][302][302] = {-1};

int R(int i, int j, int k);
int L(int i, int j, int k) {
	int &ans = dpl[i][j][k];
	if(ans != -1)
		return ans;
	
	if(k == 0)
		return ans = 0;

	if(i==0 && j==N-1)
		return ans = 0;
	
	if(!i)
		return ans = R(i,j+1,k-1)+k*(X[j+1]-X[i]);
	if(j==N-1)
		return ans = L(i-1,j,k-1)+k*(X[i]-X[i-1]);

	return ans = min(L(i-1,j,k-1)+k*(X[i]-X[i-1]), R(i,j+1,k-1)+k*(X[j+1]-X[i]));
}

int R(int i, int j, int k) {
	int &ans = dpr[i][j][k];
	if(ans != -1)
		return ans;
	
	if(k == 0)
		return ans = 0;

	if(i==0 && j==N-1)
		return ans = 0;
	
	if(!i)
		return ans = R(i,j+1,k-1)+k*(X[j+1]-X[i]);
	if(j==N-1)
		return ans = L(i-1,j,k-1)+k*(X[i]-X[i-1]);

	return ans = min(L(i-1,j,k-1)+k*(X[i]-X[i-1]), R(i,j+1,k-1)+k*(X[j+1]-X[i]));
}

int main() {
	cin>>N>>M;
	X.resize(N);
	int zero = 0;
	for(int &i:X) {
		cin>>i;
		if(!X[i])
			zero = M;
	}
	if(!zero) {
		X.push_back(0);
		N++;
	}
	sort(all(X));
	int zero_pos = distance(X.begin(), lower_bound(all(X), 0));

//	for(int i=0; i<301; ++i)
//		for(int j=0; j<301; ++j)
//			for(int k=0; k<301; ++k)
//				dpl[i][j][k] = dpr[i][j][k] = -1;

	int ans = 0;
	for(int k=1; k<N; ++k)
		ans = max(L(zero_pos,zero_pos,k), ans);
	cout<<ans+zero<<endl;
}
