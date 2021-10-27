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

    int c; cin>>c;
    while(c--) {
        int n,t,m; cin>>n>>t>>m;
        queue<pair<int,int>> q[2];
        for(int i=0; i<m; i++) {
            int time; string s;
            cin>>time>>s;
            if(s == "left")
                q[0].push(make_pair(time, i));
            else
                q[1].push(make_pair(time, i));
        }
        
        // cout<<"Q0"<<endl;
        // while(!q[0].empty()) {
        //     cout<<q[0].front()<<" ";
        //     q[0].pop();
        // }
        // cout<<endl<<"Q1"<<endl;
        // while(!q[1].empty()) {
        //     cout<<q[1].front()<<" ";
        //     q[1].pop();
        // }
        // cout<<endl;
        // return 0;

        int side = 0;
        int curTime = 0;
        vector<pair<int,int>> ans;
        while(!q[0].empty() || !q[1].empty()) {
            int currentCap = n;
            if(q[side].empty() || (q[side].front().first > curTime && !q[!side].empty() && q[!side].front().first < q[side].front().first)) {
                curTime = max(curTime, q[!side].front().first) + t;
                side = !side;
                continue;
            }

            curTime = max(curTime, q[side].front().first);
            while(!q[side].empty() && q[side].front().first <= curTime && currentCap) {
                ans.push_back(make_pair(q[side].front().second, curTime + t));
                q[side].pop();
                currentCap--;
            }

            curTime += t;
            side = !side;
        }

        sort(ans.begin(), ans.end());
        for(auto p:ans)
            cout<<p.second<<endl;
        cout<<endl;
    }
}