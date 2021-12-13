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

vector<vi> G(100);
map<string,int> M;
bool small[100] = {0};
ll ans = 0;

int getId(string s) {
    if(M.find(s) == M.end()) {
        M.insert(make_pair(s,M.size()));
        if(islower(s[0]))
            small[M[s]] = 1;
    }
    return M[s];
}

void DFS(int n, vector<bool> v, bool doubled) {
    v[n] = 1;

    for(int i:G[n]) {
        if(i == getId("end"))
            ans++;
        else if(i == getId("start"))
            continue;
        else if(small[i] && v[i]) {
            if(doubled)
                continue;
            else
                DFS(i, v, true);
        }
        else
            DFS(i, v, doubled);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin, line)) {
        int pos = line.find('-');
        string c1 = line.substr(0,pos);
        string c2 = line.substr(pos+1);
        G[getId(c1)].push_back(getId(c2));
        G[getId(c2)].push_back(getId(c1));
    }

    vector<bool> visited(M.size(), 0);
    DFS(getId("start"), visited, false);

    cout<<ans<<endl;
}