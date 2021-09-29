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

    int T; cin>>T;
    while(T--) {
        int x1,x2,y1,y2,z1,z2,r1,r2,vx1,vx2,vy1,vy2,vz1,vz2;
        cin>>x1>>y1>>z1>>r1>>vx1>>vy1>>vz1;
        cin>>x2>>y2>>z2>>r2>>vx2>>vy2>>vz2;

        int dx = x1-x2,
            dy = y1-y2,
            dz = z1-z2,
            dvx = vx1-vx2,
            dvy = vy1-vy2,
            dvz = vz1-vz2;

        int a = (dvx*dvx) + (dvy*dvy) + (dvz*dvz);
        int b = (dvx*dx) + (dx*dvx) + (dvy*dy) + (dy*dvy) + (dvz*dz) + (dz*dvz);
        int c = (dx*dx) + (dy*dy) + (dz*dz) - ((r1+r2)*(r1+r2));
        if(a == 0) {
            cout<<"No collision"<<endl;
            continue;
        }

        int rd = (b*b) - (4*a*c);
        if(rd < 0) {
            cout<<"No collision"<<endl;
            continue;
        }

        double ans1 = (-b - sqrt(rd))/(2*a);
        double ans2 = (-b + sqrt(rd))/(2*a);
        if(ans2 < 0) {
            cout<<"No collision"<<endl;
            continue;
        }

        cout<<fixed<<setprecision(3)<<ans1<<endl;
    }
}