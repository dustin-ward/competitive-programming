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

struct Player {
    string name;
    int out;
    priority_queue<ll> hand;
};

int main() {
    int N,M,P; cin>>N>>M>>P;
    vector<Player> V(N);
    for(Player &p:V) {
        cin>>p.name;

        for(int i=0; i<M; i++) {
            ll temp; cin>>temp;
            p.hand.push(-temp);
        }
    }

    sort(all(V),[](const Player &a, const Player &b){return a.name<b.name;});

    int out=0;
    while(1) {
        int minIdx = -1;
        for(int i=0; i<N; i++) {
            if(!V[i].hand.empty()) {
                if(minIdx==-1 || V[i].hand.top() > V[minIdx].hand.top())
                    minIdx=i;
            }
        }
        if(minIdx == -1) break;

        V[minIdx].hand.pop();
        if(V[minIdx].hand.empty())
            V[minIdx].out = out++;

        for(int i=0; i<N; i++) {
            if(i==minIdx) continue;
            if(V[i].hand.empty()) continue;
            ll temp = V[i].hand.top();
            V[i].hand.pop();
            V[i].hand.push(temp-P);
        }
    }

    sort(all(V),[](const Player &a, const Player &b){return a.out<b.out;});
    for(Player &p:V)
        cout<<p.name<<" ";
    cout<<endl;
}
