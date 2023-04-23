#include <bits/stdc++.h>
#include <queue>
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
    int T; cin>>T;
    while(T--) {
        int N,K; cin>>N>>K;
        vector<ll> X(N);
        priority_queue<ll> pos,neg;
        for(int i=0; i<N; i++) {
            ll temp; cin>>temp;
            if(temp>0) pos.push(-temp);
            else neg.push(temp);
        }

        ll ans=0;
        ll last;
        while(!pos.empty() && sz(pos)>=K) {
            for(int i=0; i<K-1; i++) pos.pop();
            last = 2 * -pos.top(); pos.pop();
            debug(last);
            ans += last;
        }
        bool flag = false;
        while(!pos.empty()) {
            last = -pos.top(); pos.pop();
            flag = true;
        }
        if(flag) {
            debug(last);
            ans += 2 * last;
        }

        while(!neg.empty() && sz(neg)>=K) {
            for(int i=0; i<K-1; i++) neg.pop();
            last = 2 * -neg.top(); neg.pop();
            ans += last;
        }
        flag = false;
        while(!neg.empty()) {
            last = -neg.top(); neg.pop();
            flag=true;
        }
        if(flag) {
            debug(last);
            ans += 2 * last;
        }

        if(pos.empty() && neg.empty()) ans -= last/2;
        cout<<ans<<endl;
    }
}
