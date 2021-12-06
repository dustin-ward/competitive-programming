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

    string b;
    vector<string> V;
    while(cin>>b)
        V.push_back(b);
    sort(V.begin(), V.end());
    debug(V);

    vector<bool> b1(V.size(), 1);
    int start=0,end = V.size();
    string ans1;
    for(int i=0; i<V[0].length(); i++) {
        cout<<"Start "<<start<<" end "<<end<<endl;
        if(abs(start-end) <= 1) {
            ans1 = V[start];
            break;
        }
        int o=0, z=0;
        int pos = INT_MAX;
        for(int j=start; j<end; j++) {
            if(V[j][i] == '0')
                z++;
            else {
                o++;
                pos = min(pos, j);
            }
        }
        debug(o);
        debug(z);
        if(o >= z) {
            start = pos;
            end = end;
        } else {
            start = start;
            end = pos;
        }
    }
    debug(V[start])
    ans1 = V[start];
    
    start=0,end = V.size();
    string ans2;
    for(int i=0; i<V[0].length(); i++) {
        cout<<"Start "<<start<<" end "<<end<<endl;
        if(abs(start-end) <= 1) {
            ans2 = V[start];
            break;
        }
        int o=0, z=0;
        int pos = INT_MAX;
        for(int j=start; j<end; j++) {
            if(V[j][i] == '0')
                z++;
            else {
                o++;
                pos = min(pos, j);
            }
        }
        debug(o);
        debug(z);
        if(o >= z) {
            start = start;
            end = pos;
        } else {
            start = pos;
            end = end;
        }
    }
    debug(V[start])
    ans2 = V[start];

    debug(ans1);
    debug(ans2);
    cout<<stoi(ans1,0,2)*stoi(ans2,0,2)<<endl;
}