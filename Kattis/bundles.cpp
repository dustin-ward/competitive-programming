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

int N,M;
vector<bitset<100>> B;
vi P;
vi dp;

int f(int b) {
    if(dp[b] != -1)
        return dp[b];
    
    int &ans = dp[b];
    ans = P[b];

    vi L(N, -1);
    for(int i=0; i<M; ++i) {
        if(i == b)
            continue;
        
        if(B[i] == B[b]) {
            ans = min(ans, P[i]);
            continue;
        }

        if((B[i] & ~B[b]).any())
            continue;
        
        for(int j=0; j<N; ++j) {
            if(B[i].test(j)) {
                if(L[j] == -1 || B[i].count() > B[L[j]].count())
                    L[j] = i;
            }
        }
    }

    int ans2 = 0;
    bitset<100> temp;
    for(int i=0; i<N; ++i) {
        if(L[i] == -1)
            continue;
        if((B[L[i]] & temp).any())
            continue;
        temp |= B[L[i]];
        ans2 += f(L[i]);
    }

    if(temp == B[b])
        ans = min(ans, ans2);

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        cin>>N>>M;
        B.resize(M+1);
        P.resize(M+1);
        dp.resize(M+1, -1);

        for(int i=0; i<M; ++i) {
            B[i].reset();
            cin>>P[i];
            int n; cin>>n;
            for(int j=0; j<n; ++j) {
                int x; cin>>x;
                B[i].set(x-1);
            }
        }

        B[M].reset();
        for(int i=0; i<N; ++i)
            B[M].set(i);
        P[M] = INT_MAX;

        cout<<f(M)<<endl;
    }
}