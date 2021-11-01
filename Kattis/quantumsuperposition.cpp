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

void DFS(vector<vi> &G, bool dp[1001][2001], int N, int M) {  
    vi deg(N,0);
    for(vi &i:G) {
        for(int j:i)
            deg[j]++;
    }

    queue<int> q;
    q.push(0);
    dp[0][0] = 1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int i:G[cur]) {
            for(int j=0; j<M; j++) {
                if(dp[cur][j])
                    dp[i][j+1] = 1;
            }
            deg[i]--;
            if(!deg[i])
                q.push(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N1, N2, M1, M2; cin>>N1>>N2>>M1>>M2;
    bool dp1[1001][2001], dp2[1001][2001];
    for(int i=0; i<1001; i++) {
        for(int j=0; j<2001; j++)
            dp1[i][j] = dp2[i][j] = 0;
    }

    vector<vi> G1(N1), G2(N2);
    for(int i=0; i<M1; i++) {
        int u,v; cin>>u>>v;
        G1[u-1].push_back(v-1);
    }
    for(int i=0; i<M2; i++) {
        int u,v; cin>>u>>v;
        G2[u-1].push_back(v-1);
    }

    DFS(G1, dp1, N1, M1);
    DFS(G2, dp2, N2, M2);

    set<int> sums;
    for(int i=0; i<=M1; i++) {
        for(int j=0; j<=M2; j++) {
            if(dp1[N1-1][i] && dp2[N2-1][j])
                sums.insert(i+j);
        }
    }

    int Q; cin>>Q;
    for(int i=0; i<Q; i++) {
        int q; cin>>q;
        if(sums.find(q) != sums.end())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }   
}