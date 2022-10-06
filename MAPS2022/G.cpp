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

map<string, string> nouns, phrases = {
	{"numberof","c"},
	{"amountof","m"},
	{"most","cm"},
	{"fewest","c"},
	{"least","m"},
	{"more","cm"},
	{"fewer","c"},
	{"less","m"},
	{"many","c"},
	{"much","m"},
	{"few","c"},
	{"little","m"}
};

int main() {
	int N,P; cin>>N>>P;

	for(int i=0; i<N; ++i) {
		string n,c; cin>>n>>c;
		nouns[n] = c;
	}

	cin.ignore();
	string line;
	for(int i=0; i<P; ++i) {
		getline(cin,line);
		istringstream iss(line);
		vector<string> v;
		string temp;
		while(iss>>temp)
			v.push_back(temp);

		string n,p;
		if(sz(v) == 2) {
			p = phrases[v[0]];
			n = nouns[v[1]];
		}
		else {
			p = phrases[v[0]+v[1]];
			n = nouns[v[2]];
		}

		if(p.find(n[0]) != string::npos)
			cout<<"Correct!"<<endl;
		else
			cout<<"Not on my watch!"<<endl;
	}


}
