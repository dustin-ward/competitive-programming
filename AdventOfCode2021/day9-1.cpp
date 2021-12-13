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
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

bool check(int x, int y) {
    return y >= 0 && y < N && x >= 0 && x < M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    vector<vi> B;
    
    int i=0;
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
    
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            bool low = true;
            for(int k=0; k<8; k++) {
                if(check(j+dx[k], i+dy[k])) {
                    if(B[i+dy[k]][j+dx[k]] < B[i][j]) {
                        low = false;
                        break;
                    }
                }
            }
            if(low)
                ans += 1 + B[i][j];
        }
    }
    cout<<ans<<endl;
}   