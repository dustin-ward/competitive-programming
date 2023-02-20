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

vector<vi> G;
vector<vi> visited;

int N;
int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int DP[9*6][1001][1<<4];

int getNode(int i, int j) {
	return (6*i)+j;
}

bool bounds(int i, int j) {
	return i >= 0 && i < 9 && j >= 0 && j < 6;
}

int visitedMask(int i, int j) {
	int ret = 0;
	for(int k=0; k<4; ++k) {
		int i2 = i+dy[k];
		int j2 = j+dx[k];
		if(bounds(i2,j2) && visited[i2][j2])
			ret |= 1<<k;
	}
	return ret;
}

int dfs(int n, int steps, int mask) {
	if(DP[n][steps][mask] != -1) return DP[n][steps][mask];
	if(steps == N) return DP[n][steps][mask] = 1;
	int i = n/6;
	int j = n%6;
	ll ans = 0;
	int v = 0;
	for(int k=0; k<4; ++k) {
		int i2 = i+dy[k];
		int j2 = j+dx[k];
		int n1 = getNode(i2,j2);
		if(bounds(i2,j2) && !visited[i2][j2]) {
			visited[i2][j2] = 1;
			ans += dfs(n1, steps+1, visitedMask(i2,j2));
			visited[i2][j2] = 0;
			
		}
	}
	return DP[n][steps][mask] = ans;
}

int main() {
	cin>>N;
	visited.resize(9, vi(6, 0));
	G.resize(9*6);
	for(int i=0; i<9*6; ++i)
		for(int j=0; j<1<<4; ++j)
			for(int k=0; k<1001; ++k)
				DP[i][k][j] = -1;

	for(int i=0; i<9; ++i) {
		for(int j=0; j<6; ++j) {
			for(int k=0; k<4; ++k) {
				int i2 = i+dy[k];
				int j2 = j+dx[k];
				if(bounds(i2,j2)) {
					int n1 = getNode(i,j);
					int n2 = getNode(i2,j2);
					G[n1].push_back(n2);
					G[n2].push_back(n1);
				}
			}
		}
	}

	visited[0][0] = 1;
	ll ans = dfs(0, 0, 0);

	cout<<ans<<endl;
}
