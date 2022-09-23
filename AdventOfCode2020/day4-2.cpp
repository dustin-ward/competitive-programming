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

vector<string> req = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
set<string> ECL = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int ans = 0;
    while(1) {
        map<string,string> M;
        string line;
        while(getline(cin,line) && line != "") {
            if(line == "stop") {
                cout<<ans<<endl;
                return 0;
            }
            istringstream iss(line);
            string temp;
            while(iss>>temp)
                M.emplace(temp.substr(0,3), temp.substr(4));
        }

        bool valid = true;
        for(auto s:req) {
            if(M.find(s) == M.end()) {
                valid = false;
                break;
            }
        }
        if(!valid)
            continue;

        //byr
        if(M["byr"].length() != 4)
            continue;
        int byr = stoi(M["byr"]);
        if(byr < 1920 || byr > 2002)
            continue;

        //iyr
        if(M["iyr"].length() != 4)
            continue;
        int iyr = stoi(M["iyr"]);
        if(iyr < 2010 || iyr > 2020)
            continue;

        //eyr
        if(M["eyr"].length() != 4)
            continue;
        int eyr = stoi(M["eyr"]);
        if(eyr < 2020 || eyr > 2030)
            continue;

        //hgt
        int hgt = stoi(M["hgt"].substr(0,M["hgt"].length()-2));
        string type = M["hgt"].substr(M["hgt"].length()-2);
        if(type == "cm") {
            if(hgt < 150 || hgt > 193)
                continue;
        }
        else {
            if(hgt < 59 || hgt > 76)
                continue;
        }

        //hcl
        string hcl = M["hcl"];
        if(hcl[0] != '#')
            continue;
        if(hcl.length() != 7)
            continue;
        valid = true;
        for(char c:hcl.substr(1)) {
            if(!isdigit(c)) {
                if(c < 'a' || c > 'f') {
                    valid = false;
                    break;
                }
            }
        }
        if(!valid)
            continue;
        
        //ecl
        if(ECL.find(M["ecl"]) == ECL.end())
            continue;

        //pid
        string pid = M["pid"];
        if(pid.length() != 9)
            continue;
        valid = true;
        for(char c:pid) {
            if(!isdigit(c)) {
                valid = false;
                break;
            }
        }
        if(!valid)
            continue;

        ans += valid;
    }
}