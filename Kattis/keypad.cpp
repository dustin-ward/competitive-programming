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

    int T; cin>>T;
    while(T--) {
        int r,c; cin>>r>>c;
        vector<string> V(r, string(c, '\0'));
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j)
                cin>>V[i][j];
        }

        vector<string> V2(r, string(c, '\0'));
        bool possible = true;
        set<int> rS, cS;
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(V[i][j] == '1') {
                    rS.insert(i);
                    cS.insert(j);
                }
            }
        }
        vector<string> Vcheck(r, string(c, '\0'));
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(rS.find(i) != rS.end() && cS.find(j) != cS.end())
                    Vcheck[i][j] = '1';
                else
                    Vcheck[i][j] = '0';
            }
        }
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(V[i][j] != Vcheck[i][j]) {
                    possible = false;
                    goto end;
                }
            }
        }


        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(V[i][j] == '1') {
                    bool vert = false;
                    for(int i2=0; i2<r; ++i2) {
                        if(i2 == i) continue;
                        if(V[i2][j] == '1') {
                            vert = true;
                            break;
                        }
                    }
                    bool horiz = false;
                    for(int j2=0; j2<c; ++j2) {
                        if(j2 == j) continue;
                        if(V[i][j2] == '1') {
                            horiz = true;
                            break;
                        }
                    }

                    if(vert && horiz)
                        V2[i][j] = 'I';
                    else
                        V2[i][j] = 'P';
                }
                else
                    V2[i][j] = 'N';
            }
        }
end:
        if(possible) {
            for(int i=0; i<r; ++i) {
                for(int j=0; j<c; ++j)
                    cout<<V2[i][j];
                cout<<endl;
            }
        }
        else {
            cout<<"impossible"<<endl;
        }
        cout<<"----------"<<endl;
    }
}