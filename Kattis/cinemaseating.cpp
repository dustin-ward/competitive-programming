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

int R,C;
int dr[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dc[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

bool check(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>R>>C;
    int N; cin>>N;

    vector<vector<bool>> B(R, vector<bool>(C, 0));
    for(int i=0; i<N; i++) {
        int x,y; cin>>x>>y;
        B[x-1][y-1] = 1;
    }

    // for(int k=0; k<9; k++) {
    //     int ans = 0;
    //     for(int r=0; r<R; r++) {
    //         for(int c=0; c<C; c++) {
    //             if(B[r][c]) {
    //                 for(int i=0; i<8; i++) {
    //                     if(check(r+dr[i], c+dc[i])) {

    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    vi ans(9, 0);
    for(int r=0; r<R; r++) {
        for(int c=0; c<C; c++) {
            if(!B[r][c]) continue;
            int tot = 0;
            for(int i=0; i<8; i++) {
                if(check(r+dr[i], c+dc[i])) {
                    if(B[r+dr[i]][c+dc[i]])
                        tot++;
                }
            }
            ans[tot]++;
        }
    }

    for(int& i:ans)
        cout<<i<<" ";
    cout<<endl;
}