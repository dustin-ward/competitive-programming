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

pair<ll,ll> dp[10][10][22][22][2];

pair<ll,ll> f(int P1, int P2, int S1, int S2, bool p1turn) {
    if(S1 >= 21)
        return make_pair(1, 0);
    if(S2 >= 21)
        return make_pair(0, 1);
    if(dp[P1][P2][S1][S2][p1turn].first != -1)
        return dp[P1][P2][S1][S2][p1turn];
    
    pair<ll,ll> ans = make_pair(0, 0);
    for(int d1=1; d1<=3; d1++) {
        for(int d2=1; d2<=3; d2++) {
            for(int d3=1; d3<=3; d3++) {
                int D = d1+d2+d3;
                int p1=P1,p2=P2;
                int s1=S1,s2=S2;
                if(p1turn) {
                    p1 = (p1 + D)%10;
                    s1 += p1+1;
                }
                else {
                    p2 = (p2 + D)%10;
                    s2 += p2+1;
                }

                pair<ll,ll> temp = f(p1,p2,s1,s2,!p1turn);
                ans.first += temp.first;
                ans.second += temp.second;
            }
        }
    }
    return dp[P1][P2][S1][S2][p1turn] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for(int i=0; i<10; i++) {
        for(int ii=0; ii<10; ii++) {
            for(int j=0; j<22; j++) {
                for(int jj=0; jj<22; jj++) {
                    for(int k=0; k<2; k++)
                        dp[i][ii][j][jj][k].first = -1;
                }
            }
        }
    }

    string g;
    int P1,P2;
    int S1=0,S2=0;
    cin>>g>>g>>g>>g>>P1;
    cin>>g>>g>>g>>g>>P2;
    pair<ll,ll> ans = f(--P1, --P2, S1, S2, true);
    cout<<max(ans.first, ans.second)<<endl;
}