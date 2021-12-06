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

set<int> called;
int tot = 0;

void score(vector<vi>& b) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(called.find(b[i][j]) == called.end())
                tot += b[i][j];
        }
    }
}

bool check(vector<vi>& b) {
    debug(b);
    for(int i=0; i<5; i++) {
        bool win = true;
        for(int j=0; j<5; j++) {
            if(called.find(b[i][j]) == called.end()) {
                win = false;
                break;
            }
        }

        if(win) {
            score(b);
            return true;
        }
    }
    for(int i=0; i<5; i++) {
        bool win = true;
        for(int j=0; j<5; j++) {
            if(called.find(b[j][i]) == called.end()) {
                win = false;
                break;
            }
        }

        if(win) {
            score(b);
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin, line);
    line.push_back(',');

    vi nums;

    istringstream iss(line);
    int x; char c;
    while(iss>>x>>c)
        nums.push_back(x);
    debug(nums);

    // getline(cin, line);
    vector<vector<vi>> boards;
    while(getline(cin, line)) {
        // istringstream iss(line);
        vector<vi> b(5, vi(5));
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++)
                cin>>b[i][j];
        }
        // getline(cin, line);
        boards.push_back(b);
    }
    boards.pop_back();

    // debug(boards);

    bool won = false;
    int winNum;
    for(auto num:nums) {
        called.insert(num);
        debug(called);
        for(auto& b:boards) {
            if(check(b)) {
                won = true;
                break;
            }
        }
        if(won) {
            winNum = num;
            break;
        }
    }

    debug(tot);
    debug(winNum);
    cout<<tot*winNum<<endl;
}