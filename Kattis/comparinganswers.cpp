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

int n;

void mult(vector<vi> &X, vi &Y, vi &ans) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            ans[i] += X[i][j] * Y[j];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n && n) {
        vector<vi> A(n, vi(n)), B(n, vi(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cin>>A[i][j];
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cin>>B[i][j];
        }

        bool valid = true;
        for(int t=0; t<20; t++) {
            vi v(n), Av(n, 0), Bv(n, 0), AAv(n, 0);
            for(int i=0; i<n; i++)
                v[i] = rand() % 10;
            mult(A, v, Av);
            mult(B, v, Bv);
            mult(A, Av, AAv);
            if(!equal(AAv.begin(), AAv.end(), Bv.begin())) {
                valid = false;
                break;
            }
        }

        if(valid)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}