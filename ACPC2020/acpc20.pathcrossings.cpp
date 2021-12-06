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

struct Ping {
    int p;
    int x;
    int y;
    int t;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int P,N; cin>>P>>N;
    vector<Ping> v(N);
    for(int i=0; i<N; i++) {
        int p,x,y,t; cin>>p>>x>>y>>t;
        v[i] = Ping{p,x,y,t};
    }

    sort(v.begin(), v.end(), [](Ping &a, Ping &b) {return a.t < b.t;});

    set<pair<int,int>> S;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<=i+5 && j<N; j++) {
            if(abs(v[i].t - v[j].t) > 10) break;
            if(v[i].p == v[j].p) continue;
            int dx = abs(v[i].x - v[j].x);
            int dy = abs(v[i].y - v[j].y);
            if((dx*dx)+(dy*dy) <= 1000 * 1000)
                S.insert(make_pair(min(v[i].p, v[j].p), max(v[i].p, v[j].p)));
        }
    }

    cout<<S.size()<<endl;
    for(auto p:S)
        cout<<p.first<<" "<<p.second<<endl;
}