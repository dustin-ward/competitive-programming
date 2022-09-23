#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define sz(x) (int)(x).size()
#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.first << ", " << x.second << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

struct Cube {
    ll xmin, xmax;
    ll ymin, ymax;
    ll zmin, zmax;
    int mode;
};

vector<Cube> C;

bool intersect(Cube &c, Cube &c2) {
    return c.xmin <= c2.xmax && c.xmax >= c2.xmin && c.ymin <= c2.ymax && c.ymax >= c2.ymin && c.zmin <= c2.zmax && c.zmax >= c2.zmin;
}

Cube getIntersect(Cube &c, Cube &c2) {
    Cube c3;
    c3.xmin = max(c.xmin, c2.xmin);
    c3.xmax = min(c.xmax, c2.xmax);
    c3.ymin = max(c.ymin, c2.ymin);
    c3.ymax = min(c.ymax, c2.ymax);
    c3.zmin = max(c.zmin, c2.zmin);
    c3.zmax = min(c.zmax, c2.zmax);

    c3.mode = c.mode * c2.mode;
    if(c.mode == c2.mode)
        c3.mode = -c.mode;
    else if(c.mode == 1 && c2.mode == -1)
        c3.mode = 1;

    return c3;
}

ll volume(Cube &c) {
    ll V = (c.xmax - c.xmin+1) * (c.ymax - c.ymin+1) * (c.zmax - c.zmin+1);
    return V;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line)) {
        istringstream iss(line);
        Cube c;
        string mode;
        char g;
        iss>>mode>>g>>g>>c.xmin>>g>>g>>c.xmax>>g>>g>>g>>c.ymin>>g>>g>>c.ymax>>g>>g>>g>>c.zmin>>g>>g>>c.zmax;
        c.mode = (mode == "on") ? 1 : -1;

        vector<Cube> negC;
        for(Cube &c2:C) {
            if(intersect(c, c2))
                negC.push_back(getIntersect(c, c2));
        }

        for(auto &c2:negC)
            C.push_back(c2);

        if(c.mode == 1)
            C.push_back(c);
    }

    ll ans = 0;
    for(auto &c:C)
        ans += volume(c) * c.mode;

    cout<<ans<<endl;
}