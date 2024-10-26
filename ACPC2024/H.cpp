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

int main() {
    int N; cin>>N;
    vi h(N);
    for(int &i:h) cin>>i;
    
    vi p;
    for(int i=0; i<N; i++) {
        if(i==0 || i==N-1) continue;
        if(h[i] > h[i-1] && h[i] > h[i+1])
            p.emplace_back(i);
    }
    
    // debug(p);

    vi ans(N);
    for(int pk : p) {
        // debug(pk);
        int d = 1;
        bool found = false;
        while(pk-d >= 0 || pk+d < N) {
            // debug(d);
            if((pk-d >= 0 && h[pk-d] >= h[pk]) ||
               (pk+d < N && h[pk+d] >= h[pk])) {
                // debug("found");
                ans[pk] = d;
                assert(d!=1);
                found = 1;
                break;
            }
            d++;
        }
        if(!found)
            ans[pk] = -1;
    }

    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;

    /* sort(all(p), [&h](int i, int j){return h[i]>h[j];});

    if(h[p[0]] > h[0] && h[p[0]] > h[N-1])
        ans[p[0]] = -1;
    else
        ans[p[0]] = min(p[0], (N-1)-p[0]);

    for(int i=1; i<sz(p); i++) {
        ans[i] = 
    } */
}
