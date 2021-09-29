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

#define MAX_N 10000001

bool isPrime(ll n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string a,b,c,d; 
    if(!(cin>>a>>b>>c)) {
        cout<<0<<endl;
        return 0;
    }
    if(cin>>d) {
        cout<<0<<endl;
        return 0;
    }

    if(!a.length() || !b.length() || !c.length()) {
        cout<<0<<endl;
        return 0;
    }

    if(a[0] == '0' || b[0] == '0' || c[0] == '0') {
        cout<<0<<endl;
        return 0;
    }

    for(char c:a) {
        if(!isdigit(c)) {
            cout<<0<<endl;
            return 0;
        }
    }

    for(char c:b) {
        if(!isdigit(c)) {
            cout<<0<<endl;
            return 0;
        }
    }

    for(char _c:c) {
        if(!isdigit(_c)) {
            cout<<0<<endl;
            return 0;
        }
    }

    ll x = stoll(a),
       y = stoll(b),
       z = stoll(c);

    if(x <= 3 || x > 1000000000 || x%2) {
        cout<<0<<endl;
        return 0;
    }

    if(y >= x || z >= x) {
        cout<<0<<endl;
        return 0;
    }
    
    cout<<(isPrime(y) && isPrime(z) && x == y+z)<<endl; 
}