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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N,M; cin>>N>>M;
    vector<string> T(N, string(M, '\0'));
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j)
            cin>>T[i][j];
    }

    vector<vi> ANS(N, vi(M, 0));
    int ring = 1;
    bool rings = true;
    while(rings) {
        vector<vector<bool>> v(N, vector<bool>(M, 0));
        rings = false;
        // Left->right
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j) {
                if(T[i][j] == 'T') {
                    ANS[i][j] = ring;
                    v[i][j] = 1;
                    rings = 1;
                    break;
                }
            }
        }

        //Up->Down
        for(int i=0; i<M; ++i) {
            for(int j=0; j<N; ++j) {
                if(T[j][i] == 'T') {
                    ANS[j][i] = ring;
                    v[j][i] = 1;
                    rings = 1;
                    break;
                }
            }
        }

        // Right->left
        for(int i=0; i<N; ++i) {
            for(int j=M-1; j>=0; --j) {
                if(T[i][j] == 'T') {
                    ANS[i][j] = ring;
                    v[i][j] = 1;
                    rings = 1;
                    break;
                }
            }
        }

        // Down->up
        for(int i=0; i<M; ++i) {
            for(int j=N-1; j>=0; --j) {
                if(T[j][i] == 'T') {
                    ANS[j][i] = ring;
                    v[j][i] = 1;
                    rings = 1;
                    break;
                }
            }
        }

        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j)
                T[i][j] = (v[i][j]) ? '.' : T[i][j];
        }
        ++ring;
    }

    if(ring >= 12) {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j)
                cout<<right<<setw(3)<<setfill('.')<<((ANS[i][j]) ? to_string(ANS[i][j]) : "");
            cout<<endl;
        }
    }
    else {
        for(int i=0; i<N; ++i) {
            for(int j=0; j<M; ++j)
                cout<<right<<setw(2)<<setfill('.')<<((ANS[i][j]) ? to_string(ANS[i][j]) : "");
            cout<<endl;
        }
    }
}