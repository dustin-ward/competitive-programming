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

int main() {
	int H,T; cin>>H>>T;

	int eyeW = 2 + ((H-1)*2);
	int W = 2 + 2 * eyeW;
	vector<vector<char>> pic(H+3, vector<char>(W, ' '));
	
	for(int eOff=0; eOff<W; eOff += 2+eyeW) {
		for(int i=0; i<H; ++i) {
			int rOff = (H-1) - i;
			int c = 2 + i*2;
			pic[i][eOff+rOff] = '/';
			
			int j=1;
			while(j < c-1) {
				pic[i][eOff+rOff+j] = (i < H-1 ? ' ' : '_');
				j++;
			}
			pic[i][eOff+rOff+j] = '\\';
		}
	}

	int tOff = (W/2) - T;
	for(int i=0; i<2; ++i) {
		int rOff = H+1+i;
		for(int j=0; j<2*T; j+=2) {
			pic[rOff][tOff+j] = (i ? '/' : '\\');
			pic[rOff][tOff+j+1] = (i ? '\\' : '/');
		}
	}

	for(auto &v:pic) {
		for(char c:v)
			cout<<c;
		cout<<endl;
	}
}
