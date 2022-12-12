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
    queue<int> items;
    function<int(int)> operation;    
    function<int(int)> test;    
    int count = 0;
};

vector<Monkey> M;

int main() {
    string s;
    while(getline(cin,s)) {
        Monkey m;
        
        getline(cin,s);
        s += ",";
        istringstream iss(s);
        string g;
        iss>>g>>g;
        assert(g == "items:");
        int temp;
        char c;
        while(iss>>temp>>c) {
            assert(c == ',');
            m.items.push(temp);
        }

        getline(cin,s);
        istringstream iss2(s);
        iss2>>g>>g>>g>>g;
        assert(g == "old");
        char op;
        iss2>>op;
        string rhs;
        iss2>>rhs;
        if(rhs == "old") {
            if(op == '*')
                m.operation = [](int x){ return x*x; };
            else
                m.operation = [](int x){ return x*2; };
        }
        else {
            int r = stoi(rhs);
            if(op == '*')
                m.operation = [r](int x){ return x*r; };
            else
                m.operation = [r](int x){ return x+r; };
        }

        getline(cin,s);
        istringstream iss3(s);
        iss3>>g>>g>>g;
        assert(g == "by");
        int d;
        iss3>>d;
        
        getline(cin,s);
        istringstream iss4(s);
        iss4>>g>>g>>g>>g>>g;
        assert(g == "monkey");
        int l;
        iss4>>l;

        getline(cin,s);
        istringstream iss5(s);
        iss5>>g>>g>>g>>g>>g;
        assert(g == "monkey");
        int r;
        iss5>>r;

        m.test = [=](int x){ return (x % d == 0) ? l : r; };
        getline(cin,s);
        M.push_back(m);
    }

    for(int r = 1; r<=20; r++) {
        for(auto &m:M) {
            while(!m.items.empty()) {
                int x = m.items.front();
                m.items.pop();
                x = m.operation(x);
                x /= 3;
                int idx = m.test(x);
                M[idx].items.push(x);
                m.count++;
            }
        }
    }

    sort(rall(M), [](const Monkey &a, const Monkey &b) {
        return a.count <= b.count;
    });

    cout<<M[0].count*M[1].count<<endl;
}
