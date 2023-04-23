#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

const double PI = acos(-1);
double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

#define SQR(X) ((X) * (X))

// How close to call equal
const double EPS = 1e-7;

bool dEqual(double x,double y){
  return fabs(x-y) < EPS;
}

struct Point{
  double x,y;
};

struct Line{
  Point p1,p2;
};

struct Circle{
  Point centre;
  double radius;
};

// Input of:
//  - 2 distinct points on the line
//  - The centre of the circle
//  - The radius of the circle
// Output:
//  Number of points of intersection points
//  If 1 or 2, then ans1 and ans2 contain those points.
int intersect_iline_circle(Line l,Circle c,Point& ans1,Point& ans2){
  Point p1 = l.p1;
  Point p2 = l.p2;
	
  Point circCentre = c.centre;
  double rad = c.radius;
	
  p1.x -= circCentre.x;
  p2.x -= circCentre.x;
  p1.y -= circCentre.y;
  p2.y -= circCentre.y;
	
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  double dr = SQR(dx) + SQR(dy);
  double D  = p1.x*p2.y - p2.x*p1.y;
	
  double desc = SQR(rad)*dr - SQR(D);
	
  if(dEqual(desc,0)){
    ans1.x = circCentre.x + (D*dy) / dr;
    ans1.y = circCentre.y + (-D*dx) / dr;
    return 1;
  } else if(desc < 0){
    return 0;
  }
	
  double sgn = (dy < -EPS ? -1 : 1);
	
  ans1.x = circCentre.x + (D*dy + sgn*dx*sqrt(desc)) / dr;
  ans1.y = circCentre.y + (-D*dx + abs(dy)*sqrt(desc)) / dr;
	
  ans2.x = circCentre.x + (D*dy - sgn*dx*sqrt(desc)) / dr;
  ans2.y = circCentre.y + (-D*dx - abs(dy)*sqrt(desc)) / dr;
	
  return 2;
}

int W,H;
bool pointOnBorder(Point p, Point bl) {
    return ((p.x==bl.x||p.x==bl.x+W) && (p.y >= bl.y&&p.y<=bl.y+H)) ||
           ((p.y==bl.y||p.y==bl.y+H) && (p.x >= bl.x&&p.x<=bl.x+W));
}

bool circleInRect(Circle c, Point p1) {
    return c.centre.x >= p1.x && c.centre.x <= p1.x+W &&
        c.centre.y >= p1.y && c.centre.y <= p1.y+H;
}

int main() {
    cin>>W>>H;
    int N,M; cin>>N>>M;

    vector<Circle> C(N);
    for(Circle &c:C)
        cin>>c.centre.x>>c.centre.y>>c.radius;

    for(int t=0; t<M; t++) {
        // debug(t);
        Point p1;
        cin>>p1.x>>p1.y;
        // Point p2 = {p1.x+W, p1.y};
        // Point p3 = {p1.x+W, p1.y+H};
        // Point p4 = {p1.x, p1.y+H};

        // vector<Line> rect = {
        //     {p1,p2},
        //     {p2,p3},
        //     {p3,p4},
        //     {p4,p1}
        // };

        bool bad = false;
        for(Circle &c:C) {
            // debug(make_pair(c.centre.x,c.centre.y));
            if(circleInRect(c,p1)) {
                bad = true;
                break;
            }

            Point clamped = c.centre;
            if(clamped.x > p1.x+W) clamped.x = p1.x+W;
            if(clamped.x < p1.x) clamped.x = p1.x;
            if(clamped.y > p1.y+H) clamped.y = p1.y+H;
            if(clamped.y < p1.y) clamped.y = p1.y;
            // debug(make_pair(clamped.x,clamped.y));

            int dx = (c.centre.x-clamped.x)*(c.centre.x-clamped.x);
            int dy = (c.centre.y-clamped.y)*(c.centre.y-clamped.y);
            // debug(make_pair(dx,dy));
            // debug(c.radius*c.radius);
            if(dx+dy <= c.radius*c.radius) {
                bad = true;
                break;
            }

            // for(Line &l:rect) {
            //     Point a,b;
            //     int ret = intersect_iline_circle(l,c,a,b);
            //     if(ret == 1 && pointOnBorder(a,p1)) {
            //         bad = true;
            //         break;
            //     } else if(ret == 2 && (pointOnBorder(a,p1) || pointOnBorder(b,p1))) {
            //         bad = true;
            //         break;
            //     }
            // }
        }

        cout<<(bad?"DOOMSLUG STOP!":"DOOMSLUG GO!")<<endl;
    }
}
