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

string f(pair<string,string> p, int t) {
    return p.fst + " " + p.snd + "," + to_string(t);
}

int main() {
    int N; cin>>N;

    vector<string> names(N);
    for(string &s:names)
        cin>>s;

    bool bO = true;
    bool wO = true;
    pair<string,string> W = {names[0], names[2]};
    pair<string,string> B = {names[1], names[3]};
    queue<string> Q;
    for(int i=4; i<N; ++i)
        Q.push(names[i]);

    // map<string,pii> M;
    vector<pair<string,pii>> M;

    string score; cin>>score;
    for(int t=0; t<sz(score); ++t) {
        // debug(t);
        // debug(W);
        // debug(B);
        // debug(wO);
        // debug(bO);
        if(score[t] == 'W') {
            string h = W.fst + " " + W.snd;
            if(!sz(M) || M[sz(M)-1].fst != h)
                M.emplace_back(h, make_pair(1,t));
            else {
                M[sz(M)-1].snd.fst++;
                M[sz(M)-1].snd.snd = t;
            }

            if(bO) {
                Q.push(B.snd);
                B.snd = Q.front();
                Q.pop();
                bO = !bO;
            } else {
                Q.push(B.fst);
                B.fst = B.snd;
                B.snd = Q.front();
                Q.pop();
            }
            wO = !wO;
        } else {
            string h = B.fst + " " + B.snd;
            if(!sz(M) || M[sz(M)-1].fst != h)
                M.emplace_back(h, make_pair(1,t));
            else {
                M[sz(M)-1].snd.fst++;
                M[sz(M)-1].snd.snd = t;
            }

            if(wO) {
                Q.push(W.snd);
                W.snd = Q.front();
                Q.pop();
                wO = !wO;
            } else {
                Q.push(W.fst);
                W.fst = W.snd;
                W.snd = Q.front();
                Q.pop();
            }
            bO = !bO;
        }
    }

    // vector<pair<string,pii>> ans;
    // for(auto p:M)
    //     ans.push_back(p);

    sort(begin(M), end(M), [](const pair<string,pii> &a, const pair<string,pii> &b){
        if(a.snd.fst == b.snd.fst) {
            return a.snd.snd < b.snd.snd;
        }
        return a.snd.fst > b.snd.fst;
    });

    // debug(M);

    int sc = M[0].snd.fst;
    int p = 0;
    while(M[p].snd.fst == sc)
        cout<<M[p++].fst<<endl;
}
