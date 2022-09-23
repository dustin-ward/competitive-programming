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

int dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

string A = "";
vector<vector<char>> origImg;
vector<vector<char>> newImg;
int W,H;
char d;

bool check(int y, int x) {
    return y >= 0 && y < H && x >= 0 && x < W;
}

void pad(vector<vector<char>> &Img) {
    for(auto &v:Img) {
        v.insert(v.begin(), d);
        v.push_back(d);
    }
    vector<char> temp(Img[0].size(), d);
    Img.insert(Img.begin(), temp);
    Img.push_back(temp);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin,line) && line != "")
        A += line;
    assert(A.length() == 512);

    while(getline(cin,line)) {
        istringstream iss(line);
        vector<char> v;
        for(char c:line)
            v.push_back((c == '#') ? '1' : '0');

        origImg.push_back(v);
    }

    d = '0';
    for(int step=0; step<2; step++) {
        pad(origImg);
        W = origImg[0].size();
        H = origImg.size();
        newImg = origImg;
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                string s;
                for(int k=0; k<9; k++)
                    if(check(i+dy[k], j+dx[k]))
                        s += origImg[i+dy[k]][j+dx[k]];
                    else
                        s += d;

                int pos = stoi(s, 0, 2);
                newImg[i][j] = (A[pos] == '#') ? '1' : '0';
            }
        }
        d = newImg[0][0];
        origImg = newImg;
    }

    int ans = 0;
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            ans += newImg[i][j] == '1';
        }
    }
    cout<<ans<<endl;
}