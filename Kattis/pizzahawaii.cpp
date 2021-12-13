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

struct Pizza {
    string Name;
    int m1, m2;
    set<string> S1, S2;
};

int N;
vector<Pizza> P;

bool check(string& a, string& b) {
    for(int i=0; i<N; i++) {
        set<string>& s1 = P[i].S1;
        set<string>& s2 = P[i].S2;
        if((s1.find(a) != s1.end() && s2.find(b) == s2.end()) || (s1.find(a) == s1.end() && s2.find(b) != s2.end()))
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        cin>>N;
        P.clear();
        P.resize(N);
        for(int i=0; i<N; i++) {
            cin>>P[i].Name;
            cin>>P[i].m1;
            for(int j=0; j<P[i].m1; j++) {
                string temp; cin>>temp;
                P[i].S1.insert(temp);
            }
            cin>>P[i].m2;
            for(int j=0; j<P[i].m2; j++) {
                string temp; cin>>temp;
                P[i].S2.insert(temp);
            }
        }

        set<pair<string,string>> S;
        for(int i=0; i<N; i++) {
            for(auto s1:P[i].S1) {
                for(auto s2:P[i].S2) {
                    if(check(s1, s2))
                        S.insert(make_pair(s1, s2));
                }
            }
        }

        for(auto p:S)
            cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
        cout<<endl;
    }
}