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

void print(vector<string> &v) {
    for(int i=0; i<sz(v)-1; ++i) {
        cout<<v[i]<<", ";
    }
    cout<<v[sz(v)-1]<<endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    getline(cin, line);
    getline(cin, line);
    int N = stoi(line);

    vector<vector<string>> V(N);
    for(int i=0; i<N; ++i) {
        getline(cin, line);
        int splitIdx = line.find(','); 
        while (splitIdx != string::npos) {
            V[i].push_back(line.substr(0, splitIdx));
            line = line.substr(splitIdx+2);
            splitIdx = line.find(',');
        }
        V[i].push_back(line);
    }

    debug(V);

    int ans = INT_MAX;
    vi anss(N);
    for(int i=0; i<N; ++i) {
        int c = 0;
        for(int j=0; j<N; ++j) {
            if(i == j) continue;
            int c2 = 0;
            for(int k=0; k<sz(V[i]); ++k) {
                if(V[i][k] != V[j][k])
                    c2++;
            }
            c = max(c, c2);
        }
        anss[i] = c;
        ans = min(ans, c);
    }

    for(int i=0; i<N; ++i) {
        if(anss[i] == ans)
            print(V[i]);
    }
}