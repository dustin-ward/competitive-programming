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

map<char,char> M = {
	{'1','`'},
	{'2','1'},
	{'3','2'},
	{'4','3'},
	{'5','4'},
	{'6','5'},
	{'7','6'},
	{'8','7'},
	{'9','8'},
	{'0','9'},
	{'-','0'},
	{'=','-'},
	{'W','Q'},
	{'E','W'},
	{'R','E'},
	{'T','R'},
	{'Y','T'},
	{'U','Y'},
	{'I','U'},
	{'O','I'},
	{'P','O'},
	{'[','P'},
	{']','['},
	{'\\',']'},
	{'S','A'},
	{'D','S'},
	{'F','D'},
	{'G','F'},
	{'H','G'},
	{'J','H'},
	{'K','J'},
	{'L','K'},
	{';','L'},
	{'\'',';'},
	{'X','Z'},
	{'C','X'},
	{'V','C'},
	{'B','V'},
	{'N','B'},
	{'M','N'},
	{',','M'},
	{'.',','},
	{'/','.'}
};

int main() {
	string S;

	while(getline(cin,S)) {
		for(int i=0; i<sz(S); ++i)
			S[i] = (S[i] == ' ') ? ' ' : M[S[i]];
		cout<<S<<endl;
	}
}
