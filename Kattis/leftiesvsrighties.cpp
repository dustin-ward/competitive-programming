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
    int T,N; cin>>T>>N;
    vector<pii> E(T);
    int L=0,R=0,remL=0,remR=0;
    for(int i=0; i<N; i++) {
        int t; cin>>t;
        char p; cin>>p;
        if(p == 'L') {
            E[t-1].fst++;
            remL++;
        } else {
            E[t-1].snd++;
            remR++;
        }
    }

    for(int i=0; i<T; i++) {
        if(E[i].fst==0 && E[i].snd==0) {
            cout<<-1<<endl;
            return 0;
        }
    }

    int ans = 0;
    vi V(T,0);
    for(int i=0; i<T; i++) {
        if(!E[i].fst && E[i].snd) {
            V[i]=1;
            E[i].snd--;
            R++;
            remR--;
            ans++;
        } else if(E[i].fst && !E[i].snd) {
            V[i]=1;
            E[i].fst--;
            L++;
            remL--;
            ans++;
        }
    }

    for(int i=0; i<T; i++) {
        if(!V[i]) {
            if(L<R) {
                V[i] = 1;
                E[i].fst--;
                L++;
                remL--;
                ans++;
            } else {
                V[i] = 1;
                E[i].snd--;
                R++;
                remR--;
                ans++;
            }
        }
    }
    
    while(L!=R) {
        if(L<R) {
            if(!remL) break;
            remL--;
            L++;
            ans++;
        } else if(R<L) {
            if(!remR) break;
            remR--;
            R++;
            ans++;
        }
    }

    if(L==R) cout<<ans<<endl;
    else cout<<-1<<endl;
}
