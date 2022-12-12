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

const int MONKEYS = 8;

struct Item {
    vector<ll> val;
};

struct Monkey {
    queue<Item> items;
    function<void(Item&)> operation;    
    function<int(Item&, int)> test;    
    ll count = 0;
};

vector<Monkey> M;
vi D;

int main() {
    string s;
    while(getline(cin,s)) {
        getline(cin,s);
        s += ",";
        istringstream iss(s);
        string g;
        iss>>g>>g;
        assert(g == "items:");
       
        Monkey m;

        ll temp;
        char c;
        while(iss>>temp>>c) {
            assert(c == ',');
            Item it;
            it.val = vector<ll>(MONKEYS,temp);
            m.items.push(it);
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
            m.operation = [](Item &it){
                for(int i=0; i<MONKEYS; ++i)
                    it.val[i] = (it.val[i]*it.val[i]) % D[i];
            };
        }
        else {
            ll r = stoll(rhs);
            if(op == '*') {
                m.operation = [r](Item &it){ 
                    for(int i=0; i<MONKEYS; ++i)
                        it.val[i] = (it.val[i]*r) % D[i];
                };
            }
            else {
                m.operation = [r](Item &it){ 
                    for(int i=0; i<MONKEYS; ++i)
                        it.val[i] = (it.val[i]+r) % D[i];
                };
            }
        }

        getline(cin,s);
        istringstream iss3(s);
        iss3>>g>>g>>g;
        assert(g == "by");
        ll d;
        iss3>>d;
        D.push_back(d);
        
        getline(cin,s);
        istringstream iss4(s);
        iss4>>g>>g>>g>>g>>g;
        assert(g == "monkey");
        ll l;
        iss4>>l;


        getline(cin,s);
        istringstream iss5(s);
        iss5>>g>>g>>g>>g>>g;
        assert(g == "monkey");
        ll r;
        iss5>>r;

        m.test = [=](Item &i, int m){ return i.val[m]==0 ? l : r; };
        getline(cin,s);
        M.push_back(m);
    }

    for(int r = 1; r<=10000; r++) {
        for(int m=0; m<MONKEYS; ++m) {
            while(!M[m].items.empty()) {
                Item i = M[m].items.front();
                M[m].items.pop();
                M[m].operation(i);
                ll idx = M[m].test(i,m);
                M[idx].items.push(i);
                M[m].count++;
            }
        }
    }

    sort(rall(M), [](const Monkey &a, const Monkey &b) {
        return a.count <= b.count;
    });


    cout<<M[0].count*M[1].count<<endl;
}
