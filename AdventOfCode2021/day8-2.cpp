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

// This is disgusting... dont look at this

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    int ans = 0;
    while(getline(cin, line)) {
        istringstream iss(line);

        char right1, right2;
        map<string,string> M2;
        vector<string> in(10), out(4);
        for(int i=0; i<10; i++) {
            string temp;
            iss>>temp;
            sort(temp.begin(), temp.end());
            in[i] = temp;
        }

        sort(in.begin(), in.end(), [](string& a, string& b){return a.length() < b.length();});
        // 1
        M2[in[0]] = "1";
        M2[in[2]] = "4";
        string four = in[2];
        M2[in[1]] = "7";
        M2[in[9]] = "8";
        right1 = in[0][0];
        right2 = in[0][1];

        string six;
        for(int i=0; i<3; i++) {
            if(in[6+i].find(right1) == string::npos || in[6+i].find(right2) == string::npos) {
                M2[in[6+i]] = "6";
                six = in[6+i];
            }
        }
        
        string five;
        char missing;
        for(int i=0; i<3; i++) {
            string cmp = in[3+i];
            int same = 0;
            for(auto c:cmp) {
                if(six.find(c) != string::npos)
                    same++;
                else {
                    missing = c;
                }
            }
            if(same == 5) {
                M2[in[3+i]] = "5";
                five = in[3+i];
            }
        }
        
        string three;
        for(int i=0; i<3; i++) {
            string cmp = in[3+i];
            if(cmp.find(right1) != string::npos && cmp.find(right2) != string::npos) {
                three = cmp;
                M2[three] = "3";
            }
        }
        
        string two;
        for(int i=0; i<3; i++) {
            if(in[3+i] != five && in[3+i] != three) {
                two = in[3+i];
                M2[two] = "2";
            }
        }

        for(auto s:in) {
            if(M2.find(s) == M2.end()) {
                bool missing[7] = {1,1,1,1,1,1,1};
                for(auto c1:s)
                    missing[c1 - 'a'] = 0;

                char mis;
                for(int i=0; i<7; i++) {
                    cout<<missing[i]<<" ";
                    if(missing[i])
                        mis = 'a' + i;
                }
                cout<<endl;
                cout<<"string "<<s<<" missing "<<mis<<endl;

                if(four.find(mis) != string::npos)
                    M2[s] = "0";
                else
                    M2[s] = "9";

            }
        }

        debug(M2);
            
        string g; iss>>g;
        
        string outp = "";
        for(int i=0; i<4; i++) {
            string temp;
            iss>>temp;
            sort(temp.begin(), temp.end());
            debug(temp);
            outp += M2[temp];
        }
        debug(outp);
        ans += stoi(outp);
    }
    cout<<ans<<endl;
}