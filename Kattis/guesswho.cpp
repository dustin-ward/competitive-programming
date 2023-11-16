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
    int N,M,Q; cin>>N>>M>>Q;
    vi C(N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c; cin>>c;
            if(c=='Y')
                C[i] |= (1<<j);
        }
    }

    int q = 0;
    int V = 0;
    while(Q--) {
        int i; cin>>i;
        char c; cin>>c;
        q |= (1<<(i-1));
        if(c=='Y')
            V |= (1<<(i-1));
    }
    /* debug(V); */
    /* debug(q); */
    /* bitset<15> b2(V); */
    /* bitset<15> b3(q); */
    /* debug(b2); */
    /* debug(b3); */

    vi ans;
    for(int i=0; i<N; i++) {
        /* bitset<15> b1(C[i]); */
        /* debug(b1); */
        /* bitset<15> b4(C[i]&q); */
        /* debug(b4); */
        if((C[i] & q) == V)
            ans.push_back(i+1);
    }
    if(sz(ans)>1) {
        cout<<"ambiguous"<<endl;
        cout<<sz(ans)<<endl;
    }
    else {
        cout<<"unique"<<endl;
        cout<<ans[0]<<endl;
    }
}
