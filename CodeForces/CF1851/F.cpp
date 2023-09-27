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

int N,K;

pii f(int a, int b) {
    string sa = bitset<32>(a).to_string();
    string sb = bitset<32>(b).to_string();
    /* debug(sa); */
    /* debug(sb); */

    string sc(32, '0');
    for(int i=32-K; i<32; i++) {
        if(sa[i] == '0' && sb[i] == '0')
            sc[i] = '1';
    }
    /* debug(sc); */

    pii ret;
    ret.snd = stoi(sc, nullptr, 2);
    ret.fst = (a^ret.snd)&(b^ret.snd);
    /* string tp = bitset<32>(ret.fst).to_string(); */
    /* debug(tp); */
    /* debug(ret.fst); */
    /* debug(ret.snd); */
    return ret;
}

int main() {
    int T; cin>>T;
    while(T--) {
        cin>>N>>K;
        vpii A(N);
        for(int i=0; i<N; i++) {
            int x; cin>>x;
            A[i].fst = x;
            A[i].snd = i;
        }

        sort(all(A));
        int ans = 0;
        int x,y,z;
        for(int i=0; i<N-1; i++) {
            /* debug(A[i]); */
            /* debug(A[i+1]); */
            pii res = f(A[i].fst,A[i+1].fst);
            if(res.fst > ans) {
                ans = res.fst;
                x = A[i].snd;
                y = A[i+1].snd;
                z = res.snd;
            }
        }
        cout<<x+1<<" "<<y+1<<" "<<z<<endl;
    }
}
