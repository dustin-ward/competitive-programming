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

const double EPS = 1e-8;
bool dEqual(double x,double y) { return fabs(x-y) < EPS; }

struct Point {
  double x, y;
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

ostream& operator<<(ostream& os, const Point& p){
    os << p.x << ' ' << p.y;
    return os;
}

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(double r,Point p){ p.x *= r; p.y *= r; return p; }
double operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
double len(Point p){ return sqrt(p*p); }
double cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

enum Orientation {CCW, CW, CNEITHER};

//------------------------------------------------------------------------------
// Colinearity test
bool colinear(Point a, Point b, Point c) { return dEqual(cross(b-a,c-b),0); }

//------------------------------------------------------------------------------
// Orientation test  (When pts are colinear: ccw: a-b-c  cw: c-a-b  neither: a-c-b)
Orientation ccw(Point a, Point b, Point c) { // 
  Point d1 = b - a, d2 = c - b;
  if (dEqual(cross(d1,d2),0))
    if (d1.x * d2.x < 0 || d1.y * d2.y < 0) 
      return (d1 * d1 >= d2*d2 - EPS) ? CNEITHER : CW;
    else return CCW;
  else return (cross(d1,d2) > 0) ? CCW : CW;
}

//------------------------------------------------------------------------------
// Signed Area of Polygon
double area_polygon(vector<Point> &p, int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++)  sum += cross(p[i],p[(i+1)%n]);
  return sum/2.0;
}

//------------------------------------------------------------------------------
// Convex hull: Contains co-linear points. To remove colinear points:
//   Change ("< -EPS" and "> EPS") to ("< EPS" and "> -EPS")
int convex_hull(Point P[], int n, Point hull[]){
  sort(P,P+n); n = unique(P,P+n) - P;  vector<Point> L,U;
  if(n <= 2) { copy(P,P+n,hull); return n; }
  for(int i=0;i<n;i++){
    while(L.size()>1 && cross(P[i]-L.back(),L[L.size()-2]-P[i]) < -EPS) L.pop_back();
    while(U.size()>1 && cross(P[i]-U.back(),U[U.size()-2]-P[i]) >  EPS) U.pop_back();
    L.push_back(P[i]); U.push_back(P[i]);
  }
  copy(L.begin(),L.end(),hull); copy(U.rbegin()+1,U.rend()-1,hull+L.size());
  return L.size()+U.size()-2;
}

//------------------------------------------------------------------------------
// Point in Polygon Test
const bool BOUNDARY = true;  // is boundary in polygon?
bool point_in_poly(Point poly[], int n, Point p) {
  int i, j, c = 0;
  for (i = 0; i < n; i++) 
    if (poly[i] == p ||	ccw(poly[i], poly[(i+1)%n], p) == CNEITHER) return BOUNDARY;
  
  for (i = 0, j = n-1; i < n; j = i++) 
    if (((poly[i].y <= p.y && p.y < poly[j].y) ||
	      (poly[j].y <= p.y && p.y < poly[i].y)) &&
        (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) /
	      (poly[j].y - poly[i].y) + poly[i].x))
      c = !c;
  return c;
}

//------------------------------------------------------------------------------
// Computes the distance from "c" to the infinite line defined by "a" and "b" 
double dist_line(Point a, Point b, Point c) { return fabs(cross(b-a,a-c)/len(b-a)); }

//------------------------------------------------------------------------------
// Intersection of lines (line segment or infinite line)
//      (1 == 1 intersection pt, 0 == no intersection pts, -1 == infinitely many
int intersect_line(Point a, Point b, Point c, Point d, Point &p,bool segment) {
  double num1 = cross(d-c,a-c), num2 = cross(b-a,a-c),denom = cross(b-a,d-c);
  if (!dEqual(denom, 0)) {
    double r = num1 / denom, s = num2 / denom;
    if (!segment || (0-EPS <= r && r <= 1+EPS && 0-EPS <= s && s <= 1+EPS)) {
      p = a + r*(b-a); return 1;
    } else return 0;
  }
  if (!segment) return dEqual(num1,0) ? -1 : 0; // For infinite lines, this is the end
  if (!dEqual(num1, 0)) return 0;
  if(b < a) swap(a,b); if(d < c) swap(c,d);
  if (a.x == b.x) {
    if (b.y == c.y) { p = b; return 1; }
    if (a.y == d.y) { p = a; return 1; }
    return (b.y < c.y || d.y < a.y) ? 0 : -1;
  } else if (b.x == c.x) { p = b; return 1; }
  else if (a.x == d.x) { p = a; return 1; }
  else if (b.x < c.x || d.x < a.x) return 0;
  return -1;
}

struct line {
	Point a;
	Point b;

	void sort() {
		if(b.x < a.x)
			swap(a,b);
		else if(b.x == a.x && b.y < a.y)
			swap(a,b);
	}
};

line perpendicular_bisector(Point &p1, Point &p2) {
	Point mid = {(p1.x+p2.x)/2, (p1.y+p2.y)/2};
//	double m = -1/((p2.y-p1.y)/(p2.x-p1.x));
	
	Point vec = p1 - mid;
	vec = inv(vec);

	Point mid2 = mid + vec;
	return {mid,mid2};
}

double line_test(line &L, Point &P) {
	return (L.b.y-L.a.y) * P.x + (L.a.x-L.b.x) * P.y + (L.b.x * L.a.y - L.a.x * L.b.y);
}

Point lineIntersectSeg(Point p, Point q, Point A, Point B) {
	double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y - A.x-B.y;
	double u = fabs(a*p.x + b*p.y + c);
	double v = fabs(a*q.x + b*q.y + c);
	return {(p.x*v + q.x*u)/(u+v), (p.y*v + q.y*u) / (u+v)};
}

vector<Point> cutPolygon(Point A, Point B, const vector<Point> &Q) {
	vector<Point> P;
	for (int i=0; i<(int)Q.size(); ++i) {
//		cout<<"A "<<A<<" B "<<B<<endl;
		double left1 = cross({B.x-A.x, B.y-A.y}, {Q[i].x-A.x, Q[i].y-A.y});
		double left2 = 0;
		if(i != (int)Q.size()-1) left2 = cross({B.x-A.x, B.y-A.y}, {Q[i+1].x-A.x, Q[i+1].y-A.y});
		if(left1 > -EPS) P.push_back(Q[i]);
		if(left1*left2 < -EPS) {
//			Point temp = lineIntersectSeg(Q[i], Q[i+1], A, B);
			Point temp;
			intersect_line(Q[i], Q[i+1], A, B, temp, 0);
//			cout<<"INTERSECTION BETWEEN\n";
//			cout<<Q[i].x<<" "<<Q[i].y<<" -> "<<Q[i+1].x<<" "<<Q[i+1].y<<endl;
//			cout<<A.x<<" "<<A.y<<" -> "<<B.x<<" "<<B.y<<endl;
//			cout<<" = "<<temp.x<<" "<<temp.y<<endl;
			P.push_back(temp);
		}
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());
	return P;
}

int main() {
	int N = 5;
	vector<Point> poly(5);	
	poly[0] = {0,0};
	poly[1] = {10,0};
	poly[2] = {10,10};
	poly[3] = {0,10};
	poly[4] = {0,0};

	Point lastPoint = {0,0};

	double x,y;
	string s;
	bool same = false;
	while(cin>>x>>y>>s) {
		Point curPoint = {x,y};
		if(s == "Same") {
			if(!(curPoint == lastPoint))
				same = 1;
		}
		
		if(same) {
			cout<<fixed<<setprecision(10)<<0.0<<endl;
			continue;
		}
		else {
			line L = perpendicular_bisector(lastPoint, curPoint);
//			cout<<"LINE"<<endl;
//			cout<<L.a.x<<" "<<L.a.y<<endl;
//			cout<<L.b.x<<" "<<L.b.y<<endl;

			Point P = (s=="Hotter")?curPoint:lastPoint;
			int o = ccw(L.a, L.b, P);
			if(o == CCW)
				poly = cutPolygon(L.a, L.b, poly);
			else if(o == CW)
				poly = cutPolygon(L.b, L.a, poly);
			else
				return 1;
		}
		N = poly.size();

//		cout<<"POLY"<<endl;
//		for(Point p:poly)
//			cout<<p.x<<" "<<p.y<<endl;
		cout<<fixed<<setprecision(10)<<area_polygon(poly,N)<<endl;
		lastPoint = curPoint;
	}
}
