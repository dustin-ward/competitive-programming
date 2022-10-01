#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

const double PI = acos(-1);

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

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

struct Point {
	double x;
	double y;
};

struct Triangle {
	double a2b;
	double b2c;
	double c2a;
};

double area_polygon(Point polygon[], int n) {
  double sum = 0.0;

  for (int i = 0; i < n-1; i++) {
    sum += polygon[i].x * polygon[i+1].y - polygon[i].y * polygon[i+1].x;
  }
  sum += polygon[n-1].x * polygon[0].y - polygon[n-1].y * polygon[0].x;
  return sum/2.0;
}

double dist(Point a, Point b) {
	double dx = abs(a.x - b.x);
	double dy = abs(a.y - b.y);
	return sqrt((dx*dx)+(dy*dy));
}

Triangle getTriangle(Point a, Point b, Point c) {
	Triangle T;
	T.a2b = dist(a,b);
	T.b2c = dist(b,c);
	T.c2a = dist(c,a);
	return T;
}

double outerAngle(Triangle T) {
	return PI - acos(
		((T.a2b*T.a2b) + (T.b2c*T.b2c) - (T.c2a*T.c2a)) /
		(2*T.a2b*T.b2c)
	);
}

double fracCircArea(double th, double d) {
	double total = PI * d*d;
	return total * (th / (2*PI));
}

int main() {
	int N,D,G; cin>>N>>D>>G;
	Point polygon[61];
	for(int i=0; i<N; ++i)
		cin>>polygon[i].x>>polygon[i].y;

	double ans = fabs(area_polygon(polygon, N));
	
	if(G > 0) {
		for(int i=0; i<N; ++i) {
			Triangle T = getTriangle(polygon[i], polygon[(i+1)%N], polygon[(i+2)%N]);
			ans += D * G * T.a2b;
			//ans += fracCircArea(outerAngle(T), D*G);	
			//ans += PI * (D*G)*(D*G);
		}
		double circ = PI * (D*G)*(D*G);
		double sum = 360 * (N-(N-2)) * 180;
		sum /= 360;
		sum *= circ;
		ans += circ;
	}


	cout<<fixed<<setprecision(10)<<ans<<endl;
}
