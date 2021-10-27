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

map<char, int> m;
bool parse(string s);

int mem(char c) {
    if(m.find(c) != m.end())
        return m[c];
    return 0;
}

void assignment(string s) {
    char x = s[1];
    if(isdigit(s[3]))
        m[x] = stoi(s.substr(3, (s.length()-1)-3));
    else
        m[x] = mem(s[3]) + mem(s[5]);
}

bool cond(string s) {
    char a = s[1], b = s[3];
    if(mem(a) < mem(b)) {
        int end = s.find("}", 5);
        return parse(s.substr(5,(end-5)+1));
    }
    return true;
}

bool assertion(string s) {
    char x = s[1], y = s[3];
    return mem(x) == mem(y);
}

bool parse(string s) {
    for(int i=0; i<s.length(); i++) {
        switch(s[i]) {
            case '[': {
                int end = s.find("]", i+1);
                assignment(s.substr(i,(end-i)+1));
                i = end;
                break;
            }
            case '(': {
                int end = s.find(")", i+1);
                if(!cond(s.substr(i,(end-i)+1)))
                    return false;
                i = end;
                break;
            }
            case '<': {
                int end = s.find(">", i+1);
                if(!assertion(s.substr(i,(end-i)+1)))
                    return false;
                i = end;
                break;
            }
        }
    }
    return true;
}

bool solve(string s, int i) {
    while(i < s.length() && s[i] != '?')
        i++;

    if(i >= s.length()) {
        m.clear();
        return parse(s);
    }
    
    s[i] = '1';
    if(!solve(s,i+1)) {
        s[i] = '?';
        return false;
    }
    s[i] = '0';
    if(!solve(s,i+1)) {
        s[i] = '?';
        return false;
    }
    s[i] = '?';
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        string s; cin>>s;
        m.clear();
        cout<<((solve(s,0)) ? "ASSERTIONS ALWAYS HOLD" : "ASSERTIONS INVALID")<<endl;   
    }
}