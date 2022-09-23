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

struct Point {
    int x;
    int y;
    int z;
    int r = 0;

    bool operator<(const Point &p2) const {
        if(x < p2.x)
            return true;
        else {
            if(y < p2.y)
                return true;
            else 
                return z <= p2.z;
        }
    }
};

queue<vector<Point>> scanners;
set<Point> beacons;

void rotate(vector<Point> &v) {
    switch(v[0].r) {
        case 0: case 1: case 2: case 3:
            for(auto &p:v) {
                Point p2 = p;
                p.x = p2.z;
                p.y = p2.y;
                p.z = -p2.x;
                p.r++;
            }
            break;
        case 4:
            for(auto &p:v) {
                Point p2 = p;
                p.x = p2.x;
                p.y = -p2.z;
                p.z = p2.y;
                p.r++;
            }
            break;
        case 5:
            for(auto &p:v) {
                Point p2 = p;
                p.x = p2.x;
                p.y = -p2.y;
                p.z = -p2.z;
                p.r=0;
            }
            break;
    }
}

void rotateZ(vector<Point> &v) {
    for(auto &p:v) {
        Point p2 = p;
        p.x = -p2.y;
        p.y = p2.x;
        p.z = p2.z;
    }
}

bool match(vector<Point> &v) {
    map<Point,int> D;
    for(auto &p1:v) {
        for(auto &p2:beacons) {
            Point p;

            // p1 + px = p2
            // px = p2 - p1
            p.x = p2.x - p1.x;
            p.y = p2.y - p1.y;
            p.z = p2.z - p1.z;
            D[p]++;
        }
    }

    for(auto pr:D) {
        if(pr.second >= 12) {
            for(Point &p1:v) {
                Point p2;
                p2.x = p1.x + pr.first.x;
                p2.y = p1.y + pr.first.y;
                p2.z = p1.z + pr.first.z;
                beacons.insert(p2);
            }
            return true;
        }
    }
    // cout<<"NO MATCH"<<endl;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string line;
    while(getline(cin, line)) {
        vector<Point> P;
        while(getline(cin, line) && line != "") {
            istringstream iss(line);
            Point p;
            char g;
            iss>>p.x>>g>>p.y>>g>>p.z;
            P.push_back(p);
        }
        scanners.push(P);
    }

    for(auto &p:scanners.front())
        beacons.insert(p);
    scanners.pop();

    while(!scanners.empty()) {
        cout<<"SCANNERS LEFT = "<<scanners.size()<<endl;
        cout<<"BEACONS FOUND = "<<beacons.size()<<endl;
        vector<Point> scanner = scanners.front();
        scanners.pop();

        // cout<<"TEST1"<<endl;
        bool matched = false;
        for(int i=0; i<4; i++) {
            // cout<<"TEST2"<<endl;
            rotateZ(scanner);
            for(int j=0; j<6; j++) {
                // cout<<"TEST3"<<endl;
                rotate(scanner);

                if(match(scanner)) {
                    matched = true;
                    break;
                }
                // cout<<"TEST4"<<endl;
            }
            if(matched)
                break;
        }
        if(!matched)
            scanners.push(scanner);
        // cout<<"TEST5"<<endl;
    }   
    cout<<beacons.size();
}