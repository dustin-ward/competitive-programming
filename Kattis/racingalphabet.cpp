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

map<char, int> m = {{'A',0}, 
                    {'B',1},
                    {'C',2},
                    {'D',3},
                    {'E',4},
                    {'F',5},
                    {'G',6},
                    {'H',7},
                    {'I',8},
                    {'J',9},
                    {'K',10},
                    {'L',11},
                    {'M',12},
                    {'N',13},
                    {'O',14},
                    {'P',15},
                    {'Q',16},
                    {'R',17},
                    {'S',18},
                    {'T',19},
                    {'U',20},
                    {'V',21},
                    {'W',22},
                    {'X',23},
                    {'Y',24},
                    {'Z',25},
                    {' ',26},
                    {'\'',27}
                    };

double runTime = 0.44879895;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin>>N;
    cin.ignore();
    string line;
    while(N--) {
        getline(cin, line);
        double ans = 0.0;
        double curPos = m[line[0]];
        for(int i=1; i<sz(line); i++) {
            double nextPos = m[line[i]];
            double distance = min(
                max(curPos,nextPos)-min(curPos,nextPos),
                (28-max(curPos,nextPos))+min(curPos,nextPos)
            );
            ans += distance;
            curPos = nextPos;
        }
        ans = (ans * runTime) + line.length();
        cout<<fixed<<setprecision(12)<<ans<<endl;
    }
}