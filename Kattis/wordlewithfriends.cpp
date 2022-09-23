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

int main() {
    int N,M; cin>>N>>M;
    vector<string> G(N), Gans(N);
    vi maxCount(26, 5), minCount(26, 0);
    vector<vector<int>> notAt(26, vi(5,0)), isAt(26, vi(5,0));
    string known = "-----";
    // map<char,int> cnt;
    for(int i=0; i<N; ++i) {
        cin>>G[i]>>Gans[i];
        vi green(26,0), yellow(26,0), grey(26,0);
        for(int j=0; j<5; j++) {
            if(Gans[i][j] == 'G') {
                isAt[G[i][j]-'A'][j]=1;
                known[j] = G[i][j];
                green[G[i][j]-'A']++;
            }
            if(Gans[i][j] == 'Y') {
                notAt[G[i][j]-'A'][j]=1;
                yellow[G[i][j]-'A']++;
            }
            if(Gans[i][j] == '-') {
                notAt[G[i][j]-'A'][j]=1;
                grey[G[i][j]-'A']++;
            }
        }

        for(int c=0; c<26; ++c) {
            int tot = green[c]+yellow[c];
            minCount[c] = max(minCount[c], tot);
            if(grey[c])
                maxCount[c] = min(maxCount[c], tot);
        }
    }

    for(int i=0; i<M; ++i) {
        string S; cin>>S;
        bool good = true;
        //Sum of chars
        vi v(26,0);
        for(int j=0; j<5; ++j)
            v[S[j]-'A']++;
        for(int c=0; c<26 && good; ++c) {
            if(v[c] > maxCount[c] || v[c] < minCount[c])
                good = false;
        }
        
        //Check greens
        for(int j=0; j<5 && good; ++j) {
            if(known[j] != '-' && S[j] != known[j])
                good = false;
        }
        //Check yellows
        for(int j=0; j<5 && good; ++j) {
            if(notAt[S[j]-'A'][j])
                good = false;
        }
        if(good)
            cout<<S<<endl;
    }
}