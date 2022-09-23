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

map<char, string> M = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"}
};

struct Packet {
    int V;
    int T;
    int I;
    int L;
    ll Value;
    vector<Packet> payload;
};

pair<Packet,int> getPacket(string &s, int i) {
    Packet P;
    int b_read = 6;
    P.V = stoi(s.substr(i,3), 0, 2);
    P.T = stoi(s.substr(i+3,3), 0, 2);
    if(P.T != 4) {
        P.I = stoi(s.substr(i+6,1), 0, 2);
        b_read++;
        if(P.I) {
            P.L = stoi(s.substr(i+7,11), 0, 2);
            b_read += 11;
            int count = 0;
            int b_read2 = 0;
            while(count != P.L) {
                auto p = getPacket(s, i+18+b_read2);
                b_read2 += p.second;
                count++;
                P.payload.push_back(p.first);
            }
            b_read += b_read2;
            return make_pair(P, b_read);
        }
        else {
            P.L = stoi(s.substr(i+7,15), 0, 2);
            b_read += 15;
            int b_read2 = 0;
            while(b_read2 != P.L) {
                auto p = getPacket(s, i+22+b_read2);
                b_read2 += p.second;
                P.payload.push_back(p.first);
            }
            b_read += b_read2;
            return make_pair(P, b_read);
        }
    }
    else {
        int pos = i+6;
        string val = "";
        while(1) {
            string a = s.substr(pos, 5);
            val += a.substr(1);
            pos += 5;
            b_read += 5;
            if(a[0] == '0') {
                P.Value = stoll(val, 0, 2);
                return make_pair(P, b_read);
            }
        }
    }
}

ll getVers(Packet p) {
    ll ans = 0;
    if(!p.payload.empty()) {
        for(auto p2:p.payload)
            ans += getVers(p2);
    }
    ans += p.V;
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    cin>>line;
    string b = "";
    for(char c:line)
        b += M[c];
    debug(b);

    auto x = getPacket(b, 0);
    cout<<getVers(x.first)<<endl;
}