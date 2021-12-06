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

    vector<vector<ll>> B(1000, vector<ll>(1000, 0));
    int x1,x2,y1,y2;
    char c;
    int N=0;
    while(cin>>x1>>c>>y1>>c>>c>>x2>>c>>y2) {
        if(x1 == x2) {
            for(int i=min(y1,y2); i<=max(y1,y2); i++)
                B[i][x1]++;
        }
        else if(y1 == y2) {
            for(int i=min(x1,x2); i<=max(x1,x2); i++)
                B[y1][i]++;
        }
        else {
            //up
            if(y1 < y2) {
                if(x1 < x2) {
                    while(y1 <= y2) {
                        B[y1][x1]++;
                        x1++;
                        y1++;
                    }
                }
                else {
                    while(y1 <= y2) {
                        B[y1][x1]++;
                        x1--;
                        y1++;
                    }
                }
            }
            //down
            else {
                if(x1 < x2) {
                    while(y1 >= y2) {
                        B[y1][x1]++;
                        x1++;
                        y1--;
                    }
                }
                else {
                    while(y1 >= y2) {
                        B[y1][x1]++;
                        x1--;
                        y1--;
                    }
                }
            }
        }
    }

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++)
            cout<<B[i][j]<< " ";
        cout<<endl;
    }

    ll ans = 0;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if(B[i][j] >= 2)
                ans++;
        }
    }
    cout<<ans<<endl;
}