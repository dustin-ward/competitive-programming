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

map<string,ll> dp;
int cost[4] = {1, 10, 100, 1000};

void print(vector<string> &s) {
    for(int i=0; i<5; i++) {
        cout<<s[i]<<endl;
    }
    cout<<endl;
}

ll f(vector<string> &s) {
    // print(s);
    if(s[2] == "###A#B#C#D###" && s[3] == "  #A#B#C#D#")
        return 0;

    string k = s[1]+s[2]+s[3];
    if(dp.find(k) != dp.end())
        return dp[k];

    ll &ans = dp[k];
    ans = INT_MAX;

    // Move out
    for(int c=3; c<=9; c+=2) {
        int r = 2;
        while(r<4 && s[r][c] == '.')
            r++;
        if(r==4)
            continue;
        char x = s[r][c];
        s[r][c] = '.';

        // Move left
        for(int i=c; i>=0 && s[1][i] == '.'; i--) {
            if(s[2][i] != '#')
                continue;
            s[1][i] = x;
            ans = min(ans, (cost[x-'A'] * (r-1 + c-i)) + f(s));
            s[1][i] = '.';
        }

        // Move right
        for(int i=c; i<13 && s[1][i] == '.'; i++) {
            if(s[2][i] != '#')
                continue;
            s[1][i] = x;
            ans = min(ans, (cost[x-'A'] * (r-1 + i-c)) + f(s));
            s[1][i] = '.';
        }

        s[r][c] = x;
    }

    // Move in
    for(int i=0; i<13; i++) {
        if(!isalpha(s[1][i]))
            continue;

        char x = s[1][i];

        // Find depth of destination
        int c = 3 + (x-'A')*2;
        int r = 2;
        if(s[2][c] != '.')
            continue;
        if(s[3][c] != x) {
            if(s[3][c] == '.')
                r = 3;
            else
                continue;
        }

        // Check if path is clear
        bool clear = true;
        for(int j=min(c, i+1); j<=max(c, i-1); j++) {
            if(s[1][j] != '.')
                clear = false;
        }
        if(!clear)
            continue;
        
        // Move
        s[1][i] = '.';
        s[r][c] = x;
        ans = min(ans, (cost[x-'A'] * (r-1 + abs(c-i))) + f(s));
        s[r][c] = '.';
        s[1][i] = x;
    }

    dp.insert(make_pair(s[1]+s[2]+s[3], ans));
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> V;
    for(int i=0; i<5; i++) {
        string line;
        getline(cin, line);
        V.push_back(line);
    }

    debug(V);

    cout<<f(V)<<endl;
}