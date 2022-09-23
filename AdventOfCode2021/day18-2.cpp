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

ll magnitude(string &s, int l, int r) {
    if(s[l] != '[')
        return stoll(s.substr(l,r-l));
    
    int depth = 0;
    for(int i=l; i<r; i++) {
        if(s[i] == '[')
            depth++;
        else if(s[i] == ']')
            depth--;
        else if(s[i] == ',' && depth == 1)
            return 3*magnitude(s, l+1, i) + 2*magnitude(s, i+1, r-1);
    }
    return LLONG_MIN;
}

bool explode(string &s) {
    int depth=0;
    int leftReplace = 0;
    int rightReplace = s.length();
    string s2 = "";
    for(int i=0; i<s.length(); i++) {
        if(s[i] == '[')
            depth++;
        else if(s[i] == ']')
            depth--;
        else {
            if(depth > 4 && isdigit(s[i])) {
                bool exploded = false;
                int endL = i+1;
                while(isdigit(s[endL]))
                    endL++;

                int startR = endL+1;
                if(isdigit(s[startR])) {
                    exploded = true;
                    int endR = startR+1;
                    while(isdigit(s[endR]))
                        endR++;

                    int L = stoi(s.substr(i, endL-i));
                    int R = stoi(s.substr(startR, endR-startR));
                    s2 = "0";

                    int lp = i-1;
                    while(lp >= 0 && !isdigit(s[lp]))
                        lp--;
                    if(lp >= 0) {
                        int lpr = lp+1;
                        s2 = s.substr(lpr, i-lpr-1) + s2;
                        while(isdigit(s[lp-1]))
                            lp--;
                        int lpV = stoi(s.substr(lp, lpr-lp));
                        lpV += L;
                        s2 = to_string(lpV) + s2;
                        leftReplace = lp;
                    }
                    else {
                        s2 = s.substr(0, i-1) + s2;
                    }

                    int rp = endR+1;
                    while(rp < s.length() && !isdigit(s[rp]))
                        rp++;
                    if(rp < s.length()) {
                        int rpl = rp;
                        s2 += s.substr(endR+1, rp-endR-1);
                        while(isdigit(s[rp++]));
                        int rpV = stoi(s.substr(rpl, rp-rpl));
                        rpV += R;
                        s2 += to_string(rpV);
                        rightReplace = rp-1;
                    }
                    else {
                        s2 += s.substr(endR+1);
                    }
                }

                if(exploded) {
                    s = s.substr(0,leftReplace) + s2 + s.substr(rightReplace);
                    return true;
                }
            }
        }
    }
    return false;
}

bool split(string &s) {
    for(int i=0; i<s.length()-1; i++) {
        if(isdigit(s[i])) {
            int j = i+1;
            while(isdigit(s[j]))
                j++;
            if(j-i == 1) continue;
            int V = stoi(s.substr(i, j-i));

            string s2 = "[" + to_string(V/2) + "," + to_string((V%2) ? (V/2)+1 : V/2) + "]";
            s = s.substr(0, i) + s2 + s.substr(j);

            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> eqs;
    string line;
    while(getline(cin,line))
        eqs.push_back(line);

    ll ans = 0;
    for(int i=0; i<eqs.size(); i++) {
        for(int j=0; j<eqs.size(); j++) {
            if(i == j) continue;
            string newE = "[" + eqs[i] + "," + eqs[j] + "]";
            while(explode(newE) || split(newE));
            ans = max(ans, magnitude(newE, 0, newE.length()));
        }
    }
    cout<<ans<<endl;
}