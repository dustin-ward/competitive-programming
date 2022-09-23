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

map<string,int> M;
map<int,string> M2;
int V[200000];
// int R[200000];

int getId(string s) {
    if(M.find(s) == M.end()) {
        M.insert(make_pair(s, M.size()));
        M2.insert(make_pair(M[s], s));
    }
    return M[s];
}

int find(int x) {
    if(V[x] != x) {
        V[x] = find(V[x]);
    }
    return V[x];
}

// bool merge(int x, int y) {
//     int res1, res2;
//     res1 = find(x);
//     res2 = find(y);
//     if (res1 != res2) {
//         if (R[res1] > R[res2]) {
//             V[res2] = res1;
//         }
//         else {
//             V[res1] = res2;
//             if (R[res1] == R[res2]) {
//                 R[res2]++;
//             }
//         }
//         return true;
//     }
// 	return false;
// }

int main() {
    int N; cin>>N;
    vector<string> G;
    for(int i=0; i<N*2; ++i)
        V[i] = i;
    
    for(int i=0; i<N; ++i) {
        string s1,s2; cin>>s1>>s2;
        G.push_back(s1);
        int id1 = getId(s1);
        int id2 = find(getId(s2));
        V[id1] = id2;
        // merge(id1, id2);
    }

    for(auto s:G) {
        cout<<s<<" ";
        int id = getId(s);
        id = find(id);
        cout<<M2[id]<<endl;
    }
}