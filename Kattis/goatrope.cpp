#include <bits/stdc++.h>
#define sz(S) (int)S.size()
#define debug(a) cerr << #a << " = " << a << endl;
using namespace std;

struct Point {
  double x, y;
  Point(double x=0, double y=0) : x(x), y(y) {}
  Point(const Point &p1, const Point &p2) : x(p2.x-p1.x), y(p2.y-p1.y) {}
  Point(const Point &p1, const Point &p2, double t) : x(p1.x + t*p2.x), y(p1.y+t*p2.y) {}
  double norm() {return sqrt(x*x + y*y);}
};

double dot(Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
double dist_pt_to_pt(Point p1, Point p2) {return Point(p1,p2).norm();}

double dist_pt_to_segment(Point p, Point a, Point b) {
    Point u(a,p), v(a,b); double s = dot(u,v) / dot(v,v);
    if(s < 0 || s > 1) return min(dist_pt_to_pt(p,a), dist_pt_to_pt(p,b));
    return dist_pt_to_pt(Point(a,v,s), p);
}

int main() {

    Point a,b,c;
    double x,y,x1,y1,x2,y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    a.x=x1;
    a.y=y1;
    b.x=x2;
    b.y=y2;
    c.x=x;
    c.y=y;

    Point a1;
    Point b1;
    a1.x=x2;
    a1.y=y1;
    b1.x=x1;
    b1.y=y2;

    vector<pair<Point,Point>> Lines(4);
    Lines[0].first = a;
    Lines[0].second = a1;

    Lines[1].first = a1;
    Lines[1].second = b;

    Lines[2].first = b;
    Lines[2].second = b1;

    Lines[3].first = b1;
    Lines[3].second = a;

    debug(c.x);
    debug(c.y);
    double ans = 10000000000.0;
    for(int i=0; i<4; i++) {
//        debug(Lines[i].first.x);
//        debug(Lines[i].first.y);
//        debug(Lines[i].second.x);
//        debug(Lines[i].second.y);
        double dis = dist_pt_to_segment(c, Lines[i].first, Lines[i].second);
//        debug(dis);
//        cout<<"DIS "<<dis<<endl;
        ans = min(ans, dis);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;

    // line 1- a to a1
    // line 2- a to b1
    // line 3- b1 to b
    // line 4- a1 to b
    //cout << fixed << setprecision(2) << min(min(dist_line(a, a1, c), dist_line(a, b1, c)), min(dist_line(b1, b, c), dist_line(a1, b, c))) << endl;

}
