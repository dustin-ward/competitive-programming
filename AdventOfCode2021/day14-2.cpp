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

int getIdx(string s) {
    return ((s[0]-'A') * 26) + (s[1]-'A');
}

string getStr(int i) {
    string s = "XX";
    s[0] = (i / 26) + 'A';
    s[1] = (i % 26) + 'A';
    return s;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    string S;
    getline(cin, S);
    map<char,ll> freq;
    vector<ll> V(26*26, 0);
    for(int i=0; i<S.length()-1; i++) {
        V[getIdx(S.substr(i,2))]++;
    }
    for(auto c:S)
        freq[c]++;

    getline(cin, line);

    map<string,char> M;
    while(getline(cin, line)) {
        string s1;
        char c;
        istringstream iss(line);
        iss>>s1>>c>>c>>c;
        M.insert(make_pair(s1, c));
    }

    
    for(int step=0; step<40; step++) {
        vector<ll> V2(26*26, 0);
        for(int i=0; i<V.size(); i++) {
            if(M.find(getStr(i)) != M.end()) {
                string s1 = getStr(i);
                string s2 = s1;
                string s3 = s1;
                s2[1] = M[s1];
                s3[0] = M[s1];
                V2[getIdx(s2)] += V[i];
                V2[getIdx(s3)] += V[i];
                freq[M[s1]] += V[i];
            }
            else
                V2[i] += V[i];
        }
        V = V2;
        
    }

    ll maxE = 0;
    ll minE = LLONG_MAX;
    for(auto p:freq) {
        maxE = max(maxE, p.second);
        minE = min(minE, p.second);
    }

    cout<<maxE-minE<<endl;
}