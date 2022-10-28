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

int N;
map<string,int> ID;
vector<vi> match;
vi C;
vi DP;

int getId(string s) {
	if(ID.find(s) == ID.end())
		ID[s] = ID.size();
	return ID[s];
}

int f(int mask, int pos) {
	if(!mask) return 1;
	int &ans = DP[mask];
	if(ans != -1)
		return ans;

	for(int i=pos; i<sz(C); ++i) {
		if((mask & C[i]) == C[i]) {
			if(f(mask-C[i], i+1))
				return ans = 1;
		}
	}
	return ans = 0;
}

int main() {
	while(cin>>N && N) {
		match.resize(15, vi(15, 0));
		DP.resize(1<<15, -1);

		for(int i=0; i<N; ++i) {
			string s1,s2; cin>>s1>>s2;
			int i1=getId(s1);
			int i2=getId(s2);
			match[i1][i2] = 1;
			match[i2][i1] = 1;
		}

		C.clear();
		for(int i=0; i<N; ++i) {
			for(int j=i+1; j<N; ++j) {
				for(int k=j+1; k<N; ++k) {
					if(match[i][j] && match[j][k] && match[i][k])
						C.push_back((1<<i)|(1<<j)|(1<<k));			
				}
			}
		}

		if(f((1<<N)-1, 0))
			cout<<"possible"<<endl;
		else
			cout<<"impossible"<<endl;
	}
}
