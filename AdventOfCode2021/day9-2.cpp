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
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<int> A;

int getId(int x, int y) {
    return M * y + x;
}

bool check(int x, int y) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int DFS(int n, vector<vi> &G, vector<bool> &seen) {
    if(seen[n]) return 0;
    seen[n] = 1;
    if(!G[n].size()) {
        A[n]++;
    }
    else {
        for(int i:G[n])
            DFS(i, G, seen);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    vector<vi> B;
    
    while(getline(cin, line)) {
        istringstream iss(line);
        char c;
        vi temp;
        while(iss>>c)
            temp.push_back(c-'0');
        B.push_back(temp);
    }

    N = B.size();
    M = B[0].size();
    A.resize((N*M)+1, 0);
    
    int ans = 0;
    priority_queue<int> pq;
    vector<vi> G((N*M) + 1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            for(int k=0; k<4; k++) {
                if(check(j+dx[k], i+dy[k])) {
                    if(B[i][j] < B[i+dy[k]][j+dx[k]])
                        G[getId(j+dx[k], i+dy[k])].push_back(getId(j,i));
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(B[i][j] != 9) {
                vector<bool> seen((N*M)+1, 0);
                pq.push(DFS(getId(j,i), G, seen));
            }
        }
    }

    ans = 1;
    sort(A.begin(), A.end());
    int l = A.size();
    ans *= A[l-1] * A[l-2] * A[l-3];
    cout<<ans<<endl;
}   