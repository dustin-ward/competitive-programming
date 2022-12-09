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

char other(char c) {
	if(c == '}')
		return '{';
	if(c == ']')
		return '[';
	if(c == '{')
		return '}';
	if(c == '[')
		return ']';
	return ' ';
}

int main() {
	string s; cin>>s;
//	debug(s);
	stack<pair<char,int>> S;
	S.push({s[0],0});

	int ans = 0;
	int p = 1;
	while(p < sz(s)) {
		debug(p);
//		debug(S.top());
		if(s[p] == '{' || s[p] == '[') {
			S.push({s[p],0});
		}
		else if(other(s[p]) == S.top().first) {
			int x = S.top().second;
			S.pop();
			if(S.empty()) {
				cout<<"EMPTY"<<endl;
				ans = x;
				break;
			}
			S.top().second += x;
		} else if(s.substr(p,5) == ":\"red") {
			p = s.find(other(S.top().first), p);
			S.pop();
		} else if(isdigit(s[p]) || s[p] == '-') {
			string x = ""; x += s[p++];
			while(isdigit(s[p]))
				x += s[p++];
//			debug(x);
			S.top().second += stoi(x);
			p -= 1;
		}
		p++;
	}
	cout<<ans<<endl;
}
