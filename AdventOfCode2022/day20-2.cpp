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

const ll KEY = 811589153;

void printQ(deque<pair<ll,ll>> Q) {
    cout<<"QUEUE==="<<endl;
    while(!Q.empty()) {
        cout<<"\t"<<Q.front()<<endl;
        Q.pop_front();
    }
    cout<<"==="<<endl;
}

int main() {
    deque<pair<ll,ll>> Q;

    int x;
    int N = 0;
    while(cin>>x)
        Q.emplace_back(N++, x*KEY);

//    printQ(Q);
    for(int k=0; k<10; ++k) {
        for(int i=0; i<N; ++i) {
            while(Q.front().fst != i) {
                pair<ll,ll> temp = Q.front();
                Q.pop_front();
                Q.push_back(temp);
            }

            ll dist = Q.front().snd;
            ll cp = abs(dist);
            pair<ll,ll> temp = Q.front(); Q.pop_front();
            while(cp--) {
                if(dist > 0) {
                    pair<ll,ll> temp = Q.front();
                    Q.pop_front();
                    Q.push_back(temp);
                }
                else {
                    pair<ll,ll> temp = Q.back();
                    Q.pop_back();
                    Q.push_front(temp);
                }
            }
            Q.push_front(temp);
    //        printQ(Q);
        }
    }

    while(Q.front().snd != 0) {
        pair<ll,ll> temp = Q.front();
        Q.pop_front();
        Q.push_back(temp);
    }

    ll ans = 0;
    for(int i=0; i<3; ++i) {
        for(int j=0; j<1000; ++j) {
            pair<ll,ll> temp = Q.front();
            Q.pop_front();
            Q.push_back(temp);
        }
        debug(Q.front());
        ans += Q.front().snd;
    }
    cout<<ans<<endl;
}
