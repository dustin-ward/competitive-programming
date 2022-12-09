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

void printBoard(vector<pii> &Rope) {
	vector<vector<char>> temp(OFF*2, vector<char>(OFF*2, '.'));
	for(int i=9; i>=0; --i) {
		temp[Rope[i].fst][Rope[i].snd] = i+'0';
	}
	for(int i=0; i<20; ++i) {
		for(int j=0; j<20; ++j)
			cout<<temp[i+OFF-10][j+OFF-10];
		cout<<endl;
	}
	cout<<endl;
}

void inch(pii &H, pii &T) {
	int dir = 0;
	if(H.fst-T.fst > 1)
		dir |= 1;
	if(H.snd-T.snd > 1)
		dir |= 2;
	if(T.fst-H.fst > 1)
		dir |= 4;
	if(T.snd-H.snd > 1)
		dir |= 8;

	switch(dir) {
		case 1:
			T.fst = H.fst-1;
			T.snd = H.snd;
			break;
		case 2:
			T.fst = H.fst;
			T.snd = H.snd-1;
			break;
		case 4:
			T.fst = H.fst+1;
			T.snd = H.snd;
			break;
		case 8:
			T.fst = H.fst;
			T.snd = H.snd+1;
			break;
		case 3:
			//ur
			T.fst = H.fst-1;
			T.snd = H.snd-1;
			break;
		case 9:
			//ul
			T.fst = H.fst-1;
			T.snd = H.snd+1;
			break;
		case 6:
			//dr
			T.fst = H.fst+1;
			T.snd = H.snd-1;
			break;
		case 12:
			//dl
			T.fst = H.fst+1;
			T.snd = H.snd+1;
			break;
	}
}

int main() {
	vector<vector<bool>> V(OFF*2, vector<bool>(OFF*2, 0));

	vector<pii> Rope(10, {OFF,OFF});

	char C;
	int N;
	while(cin>>C>>N) {
		switch(C) {
			case 'U':
				while(N--) {
					Rope[0].fst++;
					for(int i=1; i<10; ++i) {
						bool found = false;
						for(int k=0; k<9; ++k) {
							pii p = {Rope[i-1].fst+dy[k], Rope[i-1].snd+dx[k]};
							if(p == Rope[i]) {
								found = true;
								break;
							}
						}
						if(!found) {
							inch(Rope[i-1], Rope[i]);
						}
						if(i == 9)
							V[Rope[i].fst][Rope[i].snd] = 1;
					}
				}
				break;
			case 'R':
				while(N--) {
					Rope[0].snd++;
					for(int i=1; i<10; ++i) {
						bool found = false;
						for(int k=0; k<9; ++k) {
							pii p = {Rope[i-1].fst+dy[k], Rope[i-1].snd+dx[k]};
							if(p == Rope[i]) {
								found = true;
								break;
							}
						}
						if(!found) {
							inch(Rope[i-1], Rope[i]);
						}
						if(i == 9)
							V[Rope[i].fst][Rope[i].snd] = 1;
					}
				}
				break;
			case 'D':
				while(N--) {
					Rope[0].fst--;
					for(int i=1; i<10; ++i) {
						bool found = false;
						for(int k=0; k<9; ++k) {
							pii p = {Rope[i-1].fst+dy[k], Rope[i-1].snd+dx[k]};
							if(p == Rope[i]) {
								found = true;
								break;
							}
						}
						if(!found) {
							inch(Rope[i-1], Rope[i]);
						}
						if(i == 9)
							V[Rope[i].fst][Rope[i].snd] = 1;
					}
				}
				break;
			case 'L':
				while(N--) {
					Rope[0].snd--;
					for(int i=1; i<10; ++i) {
						bool found = false;
						for(int k=0; k<9; ++k) {
							pii p = {Rope[i-1].fst+dy[k], Rope[i-1].snd+dx[k]};
							if(p == Rope[i]) {
								found = true;
								break;
							}
						}
						if(!found) {
							inch(Rope[i-1], Rope[i]);
						}
						if(i == 9)
							V[Rope[i].fst][Rope[i].snd] = 1;
					}
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
