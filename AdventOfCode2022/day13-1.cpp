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

string strip(string s) {
    return s.substr(1, sz(s)-2);
}

int order(string L, string R) {
    if(L[0] == '[' && R[0] == '[') {
        if(L == "[]" && R == "[]")
            return 0;
        if(L == "[]")
            return 1;
        if(R == "[]")
            return -1;

        L = strip(L);
        R = strip(R);

        int lpos = 0;
        int cnt = 0;
        while(lpos < sz(L)) {
            if(!cnt && L[lpos] == ',')
                break;
            cnt += L[lpos]=='[';
            cnt -= L[lpos]==']';
            lpos++;
        }
        string l;
        if(lpos >= sz(L)) {
            l = L;
            L = "[]";
        }
        else {
            l = L.substr(0,lpos);
            L = "[" + L.substr(lpos+1) + "]";
        }

        int rpos = 0;
        cnt = 0;
        while(rpos < sz(R)) {
            if(!cnt && R[rpos] == ',')
                break;
            cnt += R[rpos]=='[';
            cnt -= R[rpos]==']';
            rpos++;
        }
        string r;
        if(rpos >= sz(R)) {
            r = R;
            R = "[]";
        }
        else {
            r = R.substr(0,rpos);
            R = "[" + R.substr(rpos+1) + "]";
        }

        int ret = order(l,r);
        if(ret != 0)
            return ret;
        else
            return order(L,R);
    }
    else if(L[0] == '[') {
        R = "[" + R + "]";
        return order(L,R);
    }
    else if(R[0] == '[') {
        L = "[" + L + "]";
        return order(L,R);
    }
    else {
        return stoi(R)-stoi(L);
    }
}

int main() {
    int ans = 0;
    string L,R,g;
    int p = 1;
    while(getline(cin,L)) {
        getline(cin,R);
        getline(cin,g);
        if(order(L,R) > 0)
            ans += p;
        p++;
    }
    cout<<ans<<endl;
}
