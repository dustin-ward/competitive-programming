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
int idx = 0;

bool check(vector<string> &V) {
    for(auto &s:V) {
        for(auto c:s)
            if(c == '\0') return true;
    }
    return false;
}

void rotateCCW(vector<string> &G) {
    vector<string> temp = G;

    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j)
            G[i][j] = temp[j][N-i-1];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N;
    
    vector<string> G(N);
    vector<string> ans(N, string(N, '\0'));
    for(string &s:G)
        cin>>s;

    string message;
    cin>>message;
    reverse(message.begin(), message.end());

    for(int r=0; r<4; ++r) {
        rotateCCW(G);

        for(int i=N-1; i>=0; --i) {
            for(int j=N-1; j>=0; --j) {
                if(G[i][j] == '.') {
                    ans[i][j] = message[idx++];
                }
            }
        }
    }

    debug(ans);

    if(check(ans))
        cout<<"invalid grille"<<endl;
    else {
        for(auto &s:ans)
            cout<<s;
        cout<<endl;
    }
}