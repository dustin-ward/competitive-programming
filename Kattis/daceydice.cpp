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

int N;

struct Point {
    int x;
    int y;

    bool operator==(Point& p) {return x == p.x && y == p.y;};
    bool valid() {return x >= 0 && x < N && y >= 0 && y < N;};
};

Point startPos, endPos;

struct Die {
    int top;
    int bottom;
    int left;
    int right;
    int up;
    int down;

    Die(int top, int bottom, int left, int right, int up, int down) :
        top(top), bottom(bottom), left(left), right(right), up(up), down(down) {}

    Die(int val) {
        up = val / 100;
        right = (val % 100) / 10;
        bottom =(val % 100) % 10;
        down = 7 - up;
        left = 7 - right;
        top = 7 - bottom;
    }

    Die moveLeft() {return Die(right, left, top, bottom, up, down);}
    Die moveRight() {return Die(left, right, bottom, top, up, down);}
    Die moveUp() {return Die(down, up, left, right, top, bottom);}
    Die moveDown() {return Die(up, down, left, right, bottom, top);}
    Die move(int dir) {
        switch(dir) {
            case 0:
                return moveLeft();
            case 1:
                return moveUp();
            case 2:
                return moveRight();
            case 3:
                return moveDown();
        }
        return Die(0);
    }
    int val() {return (up*100) + (right*10) + bottom;}
};

bool memo[21][21][667];

struct State {
    Point p;
    Die d;

    bool operator==(State& s) {return p == s.p && d.val() == s.d.val();}
    bool seen() {return memo[p.y][p.x][d.val()];}
    bool end() {return (p.x == endPos.x && p.y == endPos.y) && ((d.val() % 100) % 10) == 5;}
    friend ostream& operator<<(ostream& os, const State &s) {
        int diepos = s.d.up*100 + s.d.right*10 + s.d.bottom;
        os << "Pos: " << s.p.x << "," << s.p.y << " Die: " << diepos;
        return os;
    }
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char B[21][21];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        cin>>N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin>>B[i][j];
                if(B[i][j] == 'S')
                    startPos = Point{j,i};
                if(B[i][j] == 'H')
                    endPos = Point{j,i};

                for(int k=111; k<667; k++)
                    memo[j][i][k] = false;
            }
        }

        stack<State> S;
        S.push(State{startPos, Die(426)});
        memo[startPos.y][startPos.x][426] = true;
        bool valid = false;
        while(!S.empty()) {
            State cur = S.top(); S.pop();
            if(cur.end()) {
                valid = true;
                break;
            }

            for(int i=0; i<4; i++) {
                Point nextP = Point{cur.p.x+dx[i], cur.p.y+dy[i]};
                Die nextD = cur.d.move(i);
                if(nextP.valid() && B[nextP.y][nextP.x] != '*' && !memo[nextP.y][nextP.x][nextD.val()]) {
                    S.push(State{nextP, nextD});
                    memo[nextP.y][nextP.x][nextD.val()] = true;
                }
            }
        }
        if(valid)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}