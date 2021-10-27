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

double L,K,T1,T2,H;

double bin_search(double totalRain) {
    if(totalRain <= L)
        return totalRain;
    return max(L, (T1 - (L/(totalRain/T1))) * max(0.0, (totalRain/T1)-K) - (T2*K) + L); 
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>L>>K>>T1>>T2>>H;
    double lo=0, hi=1;
    while(bin_search(hi) <= H)
        hi *= 2;
    while(fabs(hi-lo) > 0.00000001) {
        double mid = (lo+hi)/2;
        if(bin_search(mid) < H)
            lo = mid;
        else
            hi = mid;
    }
    double minAmount = lo;

    lo=0; hi=1;
    while(bin_search(hi) <= H)
        hi *= 2;
    while(fabs(hi-lo) > 0.00000001) {
        double mid = (lo+hi)/2;
        if(bin_search(mid) <= H)
            lo = mid;
        else
            hi=mid;
    }
    cout<<fixed<<setprecision(12)<<minAmount<<" "<<lo<<endl;
}