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

const int WINDOW_SIZE = 25;
vector<ll> V;
ll Inval;

bool isSum(int idx) {
    for(int i=idx-WINDOW_SIZE; i<idx; i++) {
        for(int j=idx-WINDOW_SIZE; j<idx; j++) {
            if(V[i] == V[j]) continue;
            if(V[i]+V[j] == V[idx])
                return true;
        }
    }
    return false;
}

ll getFirstInval() {
    for(int i=WINDOW_SIZE; i<V.size(); i++) {
        if(!isSum(i)) {
            return V[i];
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    ll x;
    while(cin>>x)
        V.push_back(x);

    Inval = getFirstInval();

    for(int i=0; i<V.size()-1; i++) {
        ll minV=V[i],maxV=V[i];
        int j=i+1;
        ll sum = V[i];
        while(j<V.size()) {
            sum += V[j];
            minV = min(minV, V[j]);
            maxV = max(maxV, V[j]);
            if(sum == Inval) {
                cout<<minV+maxV<<endl;
                return 0;
            }
            if(sum > Inval)
                break;
            j++;
        }
    }
}