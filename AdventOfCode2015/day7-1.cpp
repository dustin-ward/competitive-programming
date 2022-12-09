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

enum OP {ASGN, ASGNCONST, AND, PASS, OR, NOT, LSHIFT, RSHIFT};

struct Expr {
	OP op;
	int arg1;
	int arg2;
};

vector<Expr> G;

map<string,int> ID;
int getId(string s) {
	if(!ID.count(s))
		ID[s] = ID.size();
	return ID[s];
}

vi M;
int eval(int n) {
	int &ret = M[n];
	if(ret != -1)
		return ret;

	Expr &e = G[n];
	uint16_t a,b,c;
	switch(e.op) {
		case ASGN:
			ret = eval(e.arg1);
			break;
		case ASGNCONST:
			ret = e.arg1;
			break;
		case AND:
			a = eval(e.arg1);
			b = eval(e.arg2);
			c = a & b;
			ret = c;
			break;
		case PASS:
			b = eval(e.arg2);
			c = (uint16_t)1 & b;
			ret = c;
			break;
		case OR:
			a = eval(e.arg1);
			b = eval(e.arg2);
			c = a | b;
			ret = c;
			break;
		case NOT:
			a = eval(e.arg1);
			b = ~a;
			ret = b;
			break;
		case LSHIFT:
			a = eval(e.arg1);
			c = a << e.arg2;
			ret = c;
			break;
		case RSHIFT:
			a = eval(e.arg1);
			c = a >> e.arg2;
			ret = c;
			break;
		default:
			assert(false);
	}

	return ret;
}

int main() {
	vector<string> S;
	string s;
	while(getline(cin,s))
		S.push_back(s);

	G.resize(sz(S));
	M.resize(sz(S), -1);

	for(auto &s:S) {
		Expr e;
		istringstream iss(s);
		if(s.find("AND") != -1) {
			string a,b,c,g;
			iss>>a>>g>>b>>g>>c;
			assert(g == "->");
			if(a == "1") {
				e.op = PASS;
				e.arg2 = getId(b);
			}
			else {
				e.op = AND;
				e.arg1 = getId(a);
				e.arg2 = getId(b);
			}
			G[getId(c)] = e;
		}
		else if(s.find("OR") != -1) {
			string a,b,c,g;
			iss>>a>>g>>b>>g>>c;
			assert(g == "->");
			e.op = OR;
			e.arg1 = getId(a);
			e.arg2 = getId(b);
			G[getId(c)] = e;
		}
		else if(s.find("NOT") != -1) {
			string a,b,g;
			iss>>g>>a>>g>>b;
			assert(g == "->");
			e.op = NOT;
			e.arg1 = getId(a);
			G[getId(b)] = e;
		}
		else if(s.find("LSHIFT") != -1) {
			string a,c,g;
			int b;
			iss>>a>>g>>b>>g>>c;
			assert(g == "->");
			e.op = LSHIFT;
			e.arg1 = getId(a);
			e.arg2 = b;
			G[getId(c)] = e;
		}
		else if(s.find("RSHIFT") != -1) {
			string a,c,g;
			int b;
			iss>>a>>g>>b>>g>>c;
			assert(g == "->");
			e.op = RSHIFT;
			e.arg1 = getId(a);
			e.arg2 = b;
			G[getId(c)] = e;
		}
		else {
			string a,b,g;
			iss>>a>>g>>b;
			assert(g == "->");
			if(isalpha(a[0])) {
				e.op = ASGN;
				e.arg1 = getId(a);
			}
			else {
				e.op = ASGNCONST;
				e.arg1 = stoi(a);
			}
			G[getId(b)] = e;
		}
	}
	for(auto p:ID)
		cout<<p.fst<<" "<<eval(p.snd)<<endl;
}
