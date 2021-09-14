#include <bits/stdc++.h>
using namespace std;

#define SQR(X) ((X) * (X))

// How close to call equal
const double EPS = 0.000000001;
const double PI = 3.141592653;

bool dEqual(double x,double y){
  return fabs(x-y) < EPS;
}

struct Point{
  double x,y;
  bool operator<(const Point& a) const{
    if(dEqual(x,a.x))
      return y < a.y;
    return x < a.x;
  }
};

// Prints out the ordered pair. This also accounts for the negative 0.
void print(const Point& a){
  cout << "(";
  if(fabs(a.x) < 1e-4)
    cout << "0.000";
  else
    cout << a.x;
  cout << ",";
  if(fabs(a.y) < 1e-4)
    cout << "0.000";
  else
    cout << a.y;
  cout << ")";
}

struct Circle{
  double r,x,y;
};

// Input:
//  Two circles to intersect
//
// Output:
//  Number of points of intersection points
//  If 1 (or 2), then ans1 (and ans2) contain those points.
//  If 3, then there are infinitely many. (They're the same circle)
int intersect_circle_circle(Circle c1,Circle c2,Point& ans1,Point& ans2){
	
  // If we have two singular points
  if(fabs(c1.r) < EPS && fabs(c2.r) < EPS){
    if(dEqual(c1.x,c2.x) && dEqual(c1.y,c2.y)){
      ans1.x = c1.x;
      ans1.y = c1.y;
      // Here, you need to know what the intersection of two exact points is:
      //  "return 1;" - If the points intersect at only 1 point
      //  "return 3;" - If the circles are the same
      // Note that both are true -- It all depends on the problem
      return 1;
    } else {
      return 0;
    }
  }
	
  double d = hypot(c1.x-c2.x,c1.y-c2.y);
	
  // Check if the circles are exactly the same.
  if(dEqual(c1.x,c2.x) && dEqual(c1.y,c2.y) && dEqual(c1.r,c2.r))
    return 3;
	
  // The circles are disjoint
  if(d > c1.r + c2.r + EPS)
    return 0;
	
  // One circle is contained inside the other -- No intersection
  if(d < abs(c1.r-c2.r) - EPS)
    return -1;
	
  double a = (SQR(c1.r) - SQR(c2.r) + SQR(d)) / (2*d);
  double h = sqrt(abs(SQR(c1.r) - SQR(a)));
	
  Point P;
  P.x = c1.x + a / d * (c2.x - c1.x);
  P.y = c1.y + a / d * (c2.y - c1.y);
	
  ans1.x = P.x + h / d * (c2.y - c1.y);
  ans1.y = P.y - h / d * (c2.x - c1.x);
	
  if(fabs(h) < EPS)
    return 1;
	
  ans2.x = P.x - h / d * (c2.y - c1.y);
  ans2.y = P.y + h / d * (c2.x - c1.x);
	
  return 2;
}

void insert_range(vector<pair<double,double>> &ranges, double ang1, double ang2) {
  for(int i=0; i<ranges.size(); i++) {
    if(ang2 < ranges[i].second && ang1 > ranges[i].second) {
      if(ang2 < ranges[i].first) {
        ranges[i].first = ranges[i].second;
      }
      else {
        ranges[i].second = ang2;
      }
    }
    if(ang1 > ranges[i].first && ang2 < ranges[i].first) {
      if(ang1 > ranges[i].second) {
        ranges[i].first = ranges[i].second;
      }
      else {
        ranges[i].first = ang1;
      }
    }
  }
  ranges.push_back(make_pair(ang2, ang1));
}

int main() {
    int N; cin>>N;
    vector<Circle> circles;
    vector<vector<pair<double,double>>> ranges(N);

    for(int i=0; i<N; i++) {
        double x,y,r; cin>>x>>y>>r;
        Circle c1 = {r,x,y};

        for(int j=i-1; j>=0; j--) {
            // Find intersection
            Point p1, p2;
            int x = intersect_circle_circle(c1, circles[j], p1, p2);

            if(x == 2) {
                // Calculate angles
                double ang1 = atan2(p1.y - circles[j].y, p1.x - circles[j].x);
                double ang2 = atan2(p2.y - circles[j].y, p2.x - circles[j].x);
                // cout<<"Ang1 "<<ang1<<", Ang2 "<<ang2<<endl;

                // Add ranges
                if(ang2 > ang1) {
                    // ranges[j].push_back(make_pair(-PI, ang1));
                    insert_range(ranges[j], -PI, ang1);
                    // ranges[j].push_back(make_pair(ang2, PI));
                    insert_range(ranges[j], ang2, PI);
                }
                else {
                    // ranges[j].push_back(make_pair(ang2, ang1));
                    insert_range(ranges[j], ang2, ang1);
                }
            }
            else if(x == 3 || x == -1) {
                // ranges[j].push_back(make_pair(-PI, PI));
                insert_range(ranges[j], -PI, PI);
            }
        }
        circles.push_back(c1);
    }

    // Find visible lines
    double ans = 0.0;
    for(int i=0; i<N; i++) {
        double circumference = 2 * PI * circles[i].r;
        for(int j=0; j<ranges[i].size(); j++) {
            double removeLength = circles[i].r * abs(ranges[i][j].second - ranges[i][j].first);
            circumference -= removeLength;
        }
        ans += circumference;
    }
    cout<<fixed<<setprecision(8)<<ans<<endl;
}