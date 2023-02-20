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

struct Blueprint {
    int cost[4][4];

    Blueprint() {
        for(int i=0; i<4; ++i)
            fill(cost[i], cost[i]+4, 0);
    }
};

struct State {
    int t;
    int r[4];
    int m[4];

    State() {
        t = 0;
        fill(r, r+4, 0);
        fill(m, m+4, 0);
    }

    bool operator<(const State &s) const {
        if (t != s.t) return t < s.t;
        if (!equal(r, r+4, s.r))
            return lexicographical_compare(r, r+4, s.r, s.r+4);
        return lexicographical_compare(m, m+3, s.m, s.m+3);
    }
};

Blueprint parse(string s) {
    istringstream iss(s);
    Blueprint BP;
    string g;
    iss>>g>>g;
    iss>>g>>g>>g>>g>>BP.cost[0][0]>>g;
    assert(g == "ore.");
    iss>>g>>g>>g>>g>>BP.cost[1][0]>>g;
    assert(g == "ore.");
    iss>>g>>g>>g>>g>>BP.cost[2][0]>>g>>g>>BP.cost[2][1]>>g;
    assert(g == "clay.");
    iss>>g>>g>>g>>g>>BP.cost[3][0]>>g>>g>>BP.cost[3][2]>>g;
    assert(g == "obsidian.");
    
    return BP;
}

int f(Blueprint BP) {
    int score = 0;
    map<State,int> memo;

    State starting;
    starting.r[0]=1;
    stack<State> S;
    S.push(starting);

    while(!S.empty()) {
        State s = S.top();
        S.pop();

        if(s.t == 32) {
            score = max(score, memo[s]);
            continue;
        }

        // Prune?
        int sum = s.m[3];
        int gRb = s.r[3];
        for(int i=0; i<32-s.t; ++i) {
            sum += gRb;
            gRb++;
        }
        if(sum <= score) continue;


        bool built = false;
        int possible = 0;
        for(int rb=3; rb>=0; --rb) {
            bool canBuild = true;
            for(int i=0; i<4; ++i)
                if(s.m[i] < BP.cost[rb][i])
                    canBuild = false;
            possible += canBuild;

            if(canBuild) {
                int highestCost = 0;
                for(int i=0; i<4; ++i)
                    highestCost = max(highestCost, BP.cost[i][rb]);

                if(rb != 3 && s.r[rb] >= highestCost) continue;

                // Collect resources
                State next = s;
                next.t++;
                for(int i=0; i<4; ++i)
                    next.m[i] += s.r[i];

                // Build robot
                next.r[rb]++;
                for(int i=0; i<4; i++)
                    next.m[i] -= BP.cost[rb][i];

                if(!memo.count(next) || memo[next] < next.m[3]) {
                    S.push(next);
                    memo[next] = next.m[3];
                }
                built = true;
            }

            if(rb == 3 && built)
                break;
        }

        if(possible < 3 || !built) {
            // Collect resources
            State next = s;
            next.t++;
            for(int i=0; i<4; ++i)
                next.m[i] += s.r[i];
            if(!memo.count(next) || memo[next] < next.m[3]) {
                S.push(next);
                memo[next] = next.m[3];
            }
        }
    }

    return score;
}

int main() {
    string s;
    int ans = 1;
    int id = 1;
    while(getline(cin,s)) {
        if(id > 3) continue;
        Blueprint bp = parse(s);
        int score = f(bp);
        debug(score);
        ans *= score;
        id++;
    }
    cout<<ans<<endl;
}
