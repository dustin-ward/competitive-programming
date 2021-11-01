#include <bits/stdc++.h>
using namespace std;

const double EPSILON = 1E-8;

struct Point {
   double x;
   double y;
};

struct Line {
   Point p1;
   Point p2;
};

// Library code for determining intersect between line segments
int intersect_iline(Point a, Point b, Point c, Point d, Point &p)
{
  double r;
  double denom, num1, num2;

  assert((a.x != b.x || a.y != b.y) && (c.x != d.x || c.y != d.y));

  num1 = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2 = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

  if (fabs(denom) >= EPSILON) {
    r = num1 / denom;
    p.x = a.x + r*(b.x - a.x);
    p.y = a.y + r*(b.y - a.y);
    return 1;
  } else {
    if (fabs(num1) >= EPSILON) {
      return 0;
    } else {
      return -1;
    }
  }
}

// Distance function
double distance(Point &a, Point &b) {
   return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
   int n; cin>>n;

   // Input gathering
   vector<Line> v;
   for(int i=0; i<n; i++) {
      double x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;

      Point p1 = {x1, y1};
      Point p2 = {x2, y2};
      Line temp = {p1, p2};
      v.push_back(temp);
   }

   // Try all combinations of points n^3
   double maxPerim = 0;
   for(int i=0; i<n-2; i++) {
      for(int j=i+1; j<n-1; j++) {
     for(int k=j+1; k<n; k++) {
        // Find all 3 intersections
        Point p1, p2, p3;
        if(intersect_iline(v[i].p1, v[i].p2, v[j].p1, v[j].p2, p1) != 1) {
           break;
        }
        if(intersect_iline(v[i].p1, v[i].p2, v[k].p1, v[k].p2, p2) != 1) {
           continue;
        }
        if(intersect_iline(v[j].p1, v[j].p2, v[k].p1, v[k].p2, p3) != 1) {
           continue;
        }

        // Find perimeter
        double tempPerim = distance(p1, p2) + distance(p1, p3) + distance(p2, p3);
        
        // Compare against current max
        if(tempPerim > maxPerim)
           maxPerim = tempPerim;
     }
      }
   }

   // Output answer
   if(maxPerim > 0)
      cout<<maxPerim<<endl;
   else
      cout<<"no triangle"<<endl;

}