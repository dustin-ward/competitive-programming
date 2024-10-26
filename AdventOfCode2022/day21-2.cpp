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

struct Monkey {
    bool type;
    ll val;
    string lhs;
    string rhs;
    char op;
};

map<string,Monkey> Mks;

ll f(string s) {
    Monkey M = Mks[s];
    if(M.type) return M.val;

    switch(M.op) {
        case '+':
            return f(M.lhs) + f(M.rhs);
            break;
        case '-':
            return f(M.lhs) - f(M.rhs);
            break;
        case '*':
            return f(M.lhs) * f(M.rhs);
            break;
        case '/':
            return f(M.lhs) / f(M.rhs);
            break;
        default:
            assert(false);
    }
}

int main() {
    string L;
    while(getline(cin,L)) {
        istringstream iss(L);
        Monkey M;
        string name;
        iss>>name;
        name = name.substr(0, sz(name)-1);

        string s; iss>>s;
        if(isdigit(s[0])) {
            M.type = 1;
            M.val = stoll(s);
        }
        else {
            M.type = 0;
            M.lhs = s;
            iss>>M.op;
            iss>>M.rhs;
        }
        Mks[name] = M;
    }

    int x = 1;
    while(f(Mks["root"].lhs) != f(Mks["root"].rhs)) {
        Mks["humn"].val = x;
        x = -(x+(x>0));
//        debug(Mks["humn"].val);
    }

    cout<<Mks["humn"].val<<endl;
}
