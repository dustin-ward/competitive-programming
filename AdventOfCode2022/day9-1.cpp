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

int dy[9] = {-1,-1,-1,0,1,1,1,0,0};
int dx[9] = {-1,0,1,1,1,0,-1,-1,0};

const int OFF = 2500;

int main() {
	vector<vector<bool>> V(OFF*2, vector<bool>(OFF*2,0));

	pii H = {OFF,OFF};
	pii T = {OFF,OFF};

	char C;
	int N;
	while(cin>>C>>N) {
		switch(C) {
			case 'U':
				while(N--) {
					H.fst++;
					bool found = false;
					for(int k=0; k<9; ++k) {
						pii p = {H.fst+dy[k], H.snd+dx[k]};
						if(p == T) {
							found = true;
							break;
						}
					}
					if(!found) {
						T.snd = H.snd;
						T.fst = H.fst-1;
					}
					V[T.fst][T.snd] = 1;
				}
				break;
			case 'R':
				while(N--) {
					H.snd++;
					bool found = false;
					for(int k=0; k<9; ++k) {
						pii p = {H.fst+dy[k], H.snd+dx[k]};
						if(p == T) {
							found = true;
							break;
						}
					}
					if(!found) {
						T.fst = H.fst;
						T.snd = H.snd-1;
					}
					V[T.fst][T.snd] = 1;
				}
				break;
			case 'D':
				while(N--) {
					H.fst--;
					bool found = false;
					for(int k=0; k<9; ++k) {
						pii p = {H.fst+dy[k], H.snd+dx[k]};
						if(p == T) {
							found = true;
							break;
						}
					}
					if(!found) {
						T.snd = H.snd;
						T.fst = H.fst+1;
					}
					V[T.fst][T.snd] = 1;
				}
				break;
			case 'L':
				while(N--) {
					H.snd--;
					bool found = false;
					for(int k=0; k<9; ++k) {
						pii p = {H.fst+dy[k], H.snd+dx[k]};
						if(p == T) {
							found = true;
							break;
						}
					}
					if(!found) {
						T.fst = H.fst;
						T.snd = H.snd+1;
					}
					V[T.fst][T.snd] = 1;
				}
				break;
		}
	}

	int ans = 0;
	for(auto v:V)
		for(auto b:v)
			ans += b;
	cout<<ans<<endl;
}
