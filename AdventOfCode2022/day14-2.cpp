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

const double PI = acos(-1);
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

vector<vector<char>> B;

struct Point {
    int x;
    int y;
};

int main() {
    B.resize(301, vector<char>(1000, '.'));
    string s;
    int maxY = 0;
    while(getline(cin,s)) {
        istringstream iss(s);
        char g;
        Point last;
        iss>>last.x>>g>>last.y;
        assert(g == ',');

        Point next;
        while(iss>>g>>g>>next.x>>g>>next.y) {
            for(int i=min(last.y,next.y); i<=max(last.y,next.y); ++i)
                for(int j=min(last.x,next.x); j<=max(last.x,next.x); ++j)
                    B[i][j] = '#';
                maxY = max(maxY, i);
            last = next;
        }
    }

    for(int i=0; i<1000; ++i)
        B[maxY+2][i] = '#';


    bool finished = false;
    int ans = 0;
    while(1) {
        pii sandPos = {0, 500};
        if(B[1][500] != '.' && B[1][499] != '.' && B[1][501] != '.')
            break;
        while(1) {
            assert(sandPos.fst >= 0);
            assert(sandPos.snd >= 0);
            assert(sandPos.fst < 300);
            assert(sandPos.snd < 1000);
            if(B[sandPos.fst+1][sandPos.snd] != '.') {
                if(B[sandPos.fst+1][sandPos.snd-1] != '.') {
                    if(B[sandPos.fst+1][sandPos.snd+1] != '.') {
                        break;
                    }
                    else {
                        sandPos.snd++;
                        sandPos.fst++;
                    }
                }
                else {
                    sandPos.snd--;
                    sandPos.fst++;
                }
            }
            else
                sandPos.fst++;
        
            if(sandPos.fst == 300) {
                finished = true;
                break;
            }
        }
        if(finished)
            break;
        B[sandPos.fst][sandPos.snd] = 'O';
        ans++;
    }

    cout<<ans+1<<endl;
}

