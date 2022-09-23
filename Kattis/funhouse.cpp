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

struct Direction {
    int dy;
    int dx;

    bool operator==(const Direction &d) {
        return d.dy == dy && d.dx == dx;
    }
};

Direction UP = {-1, 0};
Direction RIGHT = {0, 1};
Direction DOWN = {1, 0};
Direction LEFT = {0, -1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M;
    int caseno=0;
    while(cin>>M>>N && M) {
        pii start;
        vector<vector<char>> V(N, vector<char>(M));
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                cin>>V[i][j];
                if(V[i][j] == '*')
                    start = make_pair(i,j);
            }
        }

        Direction dir;
        if(start.first == 0)
            dir = DOWN;
        else if(start.first == N-1)
            dir = UP;
        else if(start.second == 0)
            dir = RIGHT;
        else
            dir = LEFT;

        pii pos = start;
        while(V[pos.first][pos.second] != 'x') {
            int &y = pos.first;
            int &x = pos.second;
            y += dir.dy;
            x += dir.dx;
            if(V[y][x] == '/') {
                if(dir == RIGHT)
                    dir = UP;
                else if(dir == DOWN)
                    dir = LEFT;
                else if(dir == UP)
                    dir = RIGHT;
                else
                    dir = DOWN;
            }
            else if(V[y][x] == '\\') {
                if(dir == RIGHT)
                    dir = DOWN;
                else if(dir == DOWN)
                    dir = RIGHT;
                else if(dir == UP)
                    dir = LEFT;
                else
                    dir = UP;
            }
        }
        V[pos.first][pos.second] = '&';
        cout<<"HOUSE "<<++caseno<<endl;
        for(auto& v:V) {
            for(auto& c:v)
                cout<<c;
            cout<<endl;
        }
    }
}