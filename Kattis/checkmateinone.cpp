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

int dx[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
int dy[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
char board[8][8];
pii R,K,k;

bool valid(pii &p) {
    return p.first >= 0 && p.first < 8 && p.second >= 0 && p.second < 8;
}

bool kingThreat(pii &king1, pii &king2) {
    return abs(king1.first - king2.first) <= 1 && abs(king1.second - king2.second) <= 1;
}

bool checkmate(pii &tempR, pii &tempK, pii &tempk) {
    if(!(tempR.first == tempk.first || tempR.second == tempk.second || kingThreat(K, k)))
        return false;

    for(int i=0; i<8; i++) {
        pii newk = make_pair(tempk.first + dy[i], tempk.second + dx[i]);
        if(!valid(newk))
            continue;

        if((tempR.first == newk.first || tempR.second == newk.second) && newk != tempR)
            continue;

        if(kingThreat(tempK, newk))
            continue;

        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            cin>>board[i][j];
            switch(board[i][j]) {
                case 'R':
                    R = make_pair(i,j);
                    break;
                case 'K':
                    K = make_pair(i,j);
                    break;
                case 'k':
                    k = make_pair(i,j);
                    break;
            }
        }
    }

    bool inone = false;
    for(int i=0; i<8; i++) {
        pii newR1 = make_pair(i, R.second);
        if(newR1 != R && newR1 != K && newR1 != k) {
            if(checkmate(newR1, K, k)) {
                inone = true;
                break;
            }
        }

        pii newR2 = make_pair(R.first, i);
        if(newR2 != R && newR2 != K && newR2 != k) {
            if(checkmate(newR2, K, k)) {
                inone = true;
                break;
            }
        }

        pii newK = make_pair(K.first + dy[i], K.second + dx[i]);
        if(valid(newK) && newK != R && newK != K && newK != k && !kingThreat(newK, k)) {
            if(checkmate(R, newK, k)) {
                inone = true;
                break;
            }
        }
    }

    if(inone)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}