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

struct Point {
    int x;
    int y;
    char s;
};

const double PI = acos(-1.0);

int main() {
    int N,M,Q; cin>>N>>M>>Q;

    vector<Point> V(Q);
    vector<vector<char>> B(N, vector<char>(M, 'G'));
    for(int i=0; i<Q; ++i) {
        cin>>V[i].x>>V[i].y>>V[i].s;
        V[i].x--;
        V[i].y--;
        B[V[i].y][V[i].x] = V[i].s;
    }

    for(int r=0; r<N; ++r) {
        for(int c=0; c<M; ++c) {
            if(B[r][c] != 'G') continue;
            double sum = 0;
            for(Point &p:V) {
                int dy = abs(p.y-r);
                int dx = abs(p.x-c);
                double dis = (dx*dx) + (dy*dy);
                if(p.s == '+')
                    dis = 1/sqrt(dis);
                else
                    dis = -1/sqrt(dis);

                sum += dis;
            }
            // if(r == 15 && c == 6) debug(sum);
            if(sum > (1.0/PI))
                B[r][c] = '0';
            else if(sum > (1.0/(PI*PI)))
                B[r][c] = 'O';
            else if(sum > (1.0/(PI*PI*PI)))
                B[r][c] = 'o';
            else if(sum > -(1.0/(PI*PI*PI)))
                B[r][c] = '.';
            else if(sum > -(1.0/(PI*PI)))
                B[r][c] = 'x';
            else if(sum > -(1.0/PI))
                B[r][c] = 'X';
            else
                B[r][c] = '%';
        }
    }

    for(auto &v:B) {
        for(auto c:v)
            cout<<c;
        cout<<endl;
    }
}