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

const string C = "RGUB";

int main() {
    int N; cin>>N;

    vector<vector<char>> S(N, vector<char>(4));
    map<string,int> same;
    for(auto &v : S) {
        for(int i=0; i<4; i++)
            cin>>v[i];
        string str = "";
        str.push_back(v[0]);
        str.push_back(v[1]);
        str.push_back(v[2]);
        str.push_back(v[3]);
        same[str]++;
    }

    int ans = -1;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                for(int l=k+1; l<N; l++) {

                    bool valid = true;
                    for(int a=0; a<4; a++) {
                        set<char> cols;
                        cols.insert(S[i][a]);     
                        cols.insert(S[j][a]);     
                        cols.insert(S[k][a]);     
                        cols.insert(S[l][a]);     
                        if(!(sz(cols) == 4 || sz(cols) == 1)) {
                            valid = false;
                            break;
                        }
                    }

                    if(valid) {
                        ans = 4;
                        goto end;
                    }
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {

                bool valid = true;
                for(int a=0; a<4; a++) {
                    set<char> cols;
                    cols.insert(S[i][a]);     
                    cols.insert(S[j][a]);     
                    cols.insert(S[k][a]);     
                    if(!(sz(cols) == 3 || sz(cols) == 1)) {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    ans = 3;
                    goto end;
                }
            }
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {

            bool valid = true;
            for(int a=0; a<4; a++) {
                set<char> cols;
                cols.insert(S[i][a]);     
                cols.insert(S[j][a]);     
                if(!(sz(cols) == 2 || sz(cols) == 1)) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ans = 2;
                goto end;
            }
        }
    }

    ans = 1;

end:

    for(auto &[_,v] : same)
        ans = max(ans, v);

    cout<<ans<<endl;
}
