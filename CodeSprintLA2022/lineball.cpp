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

struct setSize {
    int size;
    int rc;
    int n;
    bool operator<(const setSize &rhs) const {
        return size < rhs.size;
    }
};

int main() {
    int N,M; cin>>N>>M;

    vector<vi> B(M, vi(M, 0));
    vector<vi> S(2, vi(M, 0));
    priority_queue<setSize> pq;
    for(int i=0; i<N; ++i) {
        int x,y;
        cin>>x>>y;
        y = (M-1)-y;
        B[y][x]++;
        S[0][x]++;
        S[1][y]++;
    }
    // debug(B);

    for(int i=0; i<M; ++i) {
        setSize s1, s2;
        s1.size = S[0][i];
        s2.size = S[1][i];
        s1.n = s2.n = i;
        s1.rc = 0;
        s2.rc = 1;
        pq.push(s1);
        pq.push(s2);
    }

    int ans = 0;
    while(!pq.empty()) {
        setSize s = pq.top(); pq.pop();
        // cout<<"s: {size: "<<s.size<<" rc: "<<s.rc<<" n: "<<s.n<<"}"<<endl;
        // debug(S);
        if(s.size != S[s.rc][s.n]) {
            // cout<<"wrong size"<<endl;
            s.size = S[s.rc][s.n];
            pq.push(s);
            continue;
        }
        if(!s.size) {
            // cout<<"empty"<<endl;
            break;
        }

        ans++;
        if(s.rc) {
            for(int i=0; i<M; ++i) {
                if(B[s.n][i])
                    S[0][i] -= B[s.n][i];
                B[s.n][i] = 0;
            }
            S[1][s.n] = 0;
        }
        else {
            for(int i=0; i<M; ++i) {
                if(B[i][s.n])
                    S[1][i] -= B[i][s.n];
                B[i][s.n] = 0;
            }
            S[0][s.n] = 0;
        }
    }
    cout<<ans<<endl;
}