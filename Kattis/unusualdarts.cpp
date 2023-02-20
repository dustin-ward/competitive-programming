#include <algorithm>
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

const double EPSILON = 1E-8;
const double EPSILON2 = 1E-5;

struct Point {
  double x, y;

  bool operator==(const Point &p) {
    return fabs(x-p.x)<EPSILON && fabs(y-p.y)<EPSILON;
  }
};

/* returns 1 if intersect at a point, 0 if not, -1 if the lines coincide */
int intersect_line(Point a, Point b, Point c, Point d, Point &p)
{
  Point t;
  double r, s;
  double denom, num1, num2;

  assert((a.x != b.x || a.y != b.y) && (c.x != d.x || c.y != d.y));

  num1 = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2 = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);

  if (fabs(denom) >= EPSILON) {
    r = num1 / denom;
    s = num2 / denom;
    if (0-EPSILON <= r && r <= 1+EPSILON && 
        0-EPSILON <= s && s <= 1+EPSILON) {
      /* always do this part if we are interested in lines instead */
      /* of line segments                                          */
      p.x = a.x + r*(b.x - a.x);
      p.y = a.y + r*(b.y - a.y);
      return 1;
    } else {
      return 0;
    }
  } else {
    if (fabs(num1) >= EPSILON) {
      return 0;
    } else {
      /* I am not using "fuzzy comparisons" here, because the comparisons */
      /* are based on the input, not some derived quantities.  You may    */
      /* want to change that if the input points are computed somehow.    */

      /* two lines are the "same".  See if they overlap */
      if (a.x > b.x || (a.x == b.x && a.y > b.y)) {
        t = a;
        a = b;
        b = t;
      }
      if (c.x > d.x || (c.x == d.x && c.y > d.y)) {
        t = c;
        c = d;
        d = t;
      }
      if (a.x == b.x) {
        /* vertical lines */
        if (b.y == c.y) {
          p = b;
          return 1;
        } else if (a.y == d.y) {
          p = a;
          return 1;
        } else if (b.y < c.y || d.y < a.y) {
          return 0;
        } else {
          return -1;
        }
      } else {
        if (b.x == c.x) {
          p = b;
          return 1;
        } else if (a.x == d.x) {
          p = a;
          return 1;
        } else if (b.x < c.x || d.x < a.x) {
          return 0;
        } else {
          return -1;
        }
      }

      return -1;
    }
  }
}

double area_polygon(Point polygon[], int n)
{
  double sum = 0.0;

  for (int i = 0; i < n-1; i++) {
    sum += polygon[i].x * polygon[i+1].y - polygon[i].y * polygon[i+1].x;
  }
  sum += polygon[n-1].x * polygon[0].y - polygon[n-1].y * polygon[0].x;
  return sum/2.0;
}

int main() {
    int N; cin>>N;
    while(N--) {
        Point D[7];
        for(auto &p:D)
            cin>>p.x>>p.y;

        double P; cin>>P;

        vi order = {0,1,2,3,4,5,6};

        do {
            // Check for complex polygon
            bool complex = false;
            for(int i=0; i<6; ++i) {
                Point a = D[order[i]];
                Point b = D[order[(i+1)%7]];
                for(int j=i+2; j<7; ++j) {
                    Point c = D[order[j]];
                    Point d = D[order[(j+1)%7]];

                    Point p;
                    int res = intersect_line(a,b,c,d,p);
                    if(res == 1 && !(p == a || p == b)) {
                        complex = 1;
                        break;
                    }
                }
                if(complex) break;
            }
            if(complex) continue;

            // Compute area
            Point poly[7];
            for(int i=0; i<7; ++i)
                poly[i] = D[order[i]];
            double area = fabs(area_polygon(poly, 7));
            double pArea = area/4.0;

            // Check prob
            double pWin = pArea*pArea*pArea;
            // debug(order);
            // debug(pWin);
            if(fabs(pWin-P) < EPSILON2)
                break;

        } while(next_permutation(all(order)));

        for(int &i:order)
            cout<<i+1<<" ";
        cout<<endl;
    }
}
