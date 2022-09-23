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

int R,C;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
vector<vi> tree_count;
vector<vector<char>> B;

bool bounds(int i, int j) {
    return i >= 0 && i < R && j >= 0 && j < C;
}

bool valid(int i, int j) {
    if(B[i][j] == '^' || B[i][j] == '#')
        return false;
//   for(int k=0; k<4; ++k) {
//        int i1=i+dy[k], j1=j+dx[k];
//        if(bounds(i1,j1) && tree_count[i1][j1] >= 2)
//            return false;
//    }
    return true;
}

int main() {
    int T,caseno=1; cin>>T;
    while(T--) {
        cin>>R>>C;
        tree_count = vector<vi>(R, vi(C, 0));
        B = vector<vector<char>>(R, vector<char>(C, '.'));
        deque<pii> D;
        for(int i=0; i<R; ++i) {
            for(int j=0; j<C; ++j) {
                cin>>B[i][j];
                if(B[i][j] == '^') {
                    for(int k=0; k<4; ++k) {
                        int i1=i+dy[k], j1=j+dx[k];
                        if(bounds(i1,j1))
                            tree_count[i1][j1]++;
                    }
                    D.push_back({i,j});
                }
            }
        }

        bool valid_board = true;
        while(!D.empty()) {
            //debug(B);
            //debug(tree_count);
            auto p = D.front(); D.pop_front();
            int i=p.first, j=p.second;
            //cout<<"AT: "<<i<<" "<<j<<endl;
            if(tree_count[i][j] >= 2)
                continue;

            bool placed = false;
            for(int k=0; k<4; ++k) {
                int i1=i+dy[k], j1=j+dx[k];
                if(bounds(i1,j1) && valid(i1,j1)) {
                    //cout<<"PLACING "<<i1<<" "<<j1<<endl;
                    for(int k1=0; k1<4; ++k1) {
                        int i2=i1+dy[k1], j2=j1+dx[k1];
                        if(bounds(i2,j2))
                            tree_count[i2][j2]++;
                    }
                    B[i1][j1] = '^';
                    D.push_front({i1,j1});
                    placed = true;
                    break;
                }
            }
            if(!placed) {
                valid_board = false;
                break;
            }
            if(tree_count[i][j] < 2)
                D.push_back({i,j});
        }
        cout<<"Case #"<<caseno++<<": "<<((valid_board) ? "Possible" : "Impossible")<<endl;
        if(valid_board) {
            for(auto& v:B) {
                for(auto c:v)
                    cout<<c;
                cout<<endl;
            }
        }
    }
}
