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

bool prime[10000001];

int main() {
    memset(prime, 1, sizeof(prime));
    for(int p=2; p*p <= 10000001; p++) {
        if(prime[p]) {
            for(int i=p*p; i<=10000001; i+=p)
                prime[i] = 0;
        }
    }

    int T; cin>>T;
    while(T--) {
        int L,R; cin>>L>>R;
        if(R-L >= 3 || (R-L>=2 && !(L%2))) {
            if(L%2)L++;
            cout<<L<<" "<<2<<endl;
            continue;
        }
        while(L<R && prime[L]) L++;
        if(L==R) {
           if(prime[L]) {
               cout<<-1<<endl;
           } else {
               bool flag = 0;
               for(int i=2; i<L; i++) {
                   if(!((L-i)%i)) {
                    cout<<L-i<<" "<<i<<endl;
                    flag = 1;
                    break;
                   }
               }
               if(!flag)
                   cout<<-1<<endl;
           }
        }
        else {
            if(L%2)
                cout<<L-1<<" "<<2<<endl;
            else
                cout<<L-2<<" "<<2<<endl;
        }
    }
}
