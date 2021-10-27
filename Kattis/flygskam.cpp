#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
pair<double,double> coords[10001];

const double PI = acos(-1.0);

double greatcircle(double lat1, double long1, double lat2, double long2,
		   double radius)
{
  lat1 *= PI/180.0;
  lat2 *= PI/180.0;
  long1 *= PI/180.0;
  long2 *= PI/180.0;
  
  double dlong = long2 - long1;
  double dlat = lat2 - lat1;
  double a = sin(dlat/2)*sin(dlat/2) +
    cos(lat1)*cos(lat2)*sin(dlong/2)*sin(dlong/2);
  return radius * 2 * atan2(sqrt(a), sqrt(1-a));
}

struct Edge {
  int to;
  double weight;       // can be double or other numeric type
  Edge(int t, double w)
    : to(t), weight(w) { }
};
  
typedef vector<Edge>::iterator EdgeIter;

struct Graph {
  vector<Edge> *nbr;
  int num_nodes;
  Graph(int n)
    : num_nodes(n)
  {
    nbr = new vector<Edge>[num_nodes];
  }

  ~Graph()
  {
    delete[] nbr;
  }

  // note: There is no check on duplicate edge, so it is possible to
  // add multiple edges between two vertices
  //
  // If this is an undirected graph, be sure to add an edge both
  // ways
  void add_edge(int u, int v, double weight)
  {
    nbr[u].push_back(Edge(v, weight));
  }
};

/* assume that D and P have been allocated */
void dijkstra(const Graph &G, int src, vector<double> &D, vector<int> &P)
{
  typedef pair<double,int> pii;

  int n = G.num_nodes;
  vector<bool> used(n, false);
  priority_queue<pii, vector<pii>,  greater<pii> > fringe;

  D.resize(n);
  P.resize(n);
  fill(D.begin(), D.end(), -1);
  fill(P.begin(), P.end(), -1);

  D[src] = 0;
  fringe.push(make_pair(D[src], src));

  while (!fringe.empty()) {
    pii next = fringe.top();
    fringe.pop();
    int u = next.second;
    if (used[u]) continue;
    used[u] = true;

    for (EdgeIter it = G.nbr[u].begin(); it != G.nbr[u].end(); ++it) {
      int v = it->to;
      double weight = it->weight + next.first;
      if (used[v]) continue;
      if (D[v] == -1 || weight < D[v]) {
	D[v] = weight;
	P[v] = u;
	fringe.push(make_pair(D[v], v));
      }
    }
  }
}

int main() {
	int N,M; cin>>N>>M;
	string S,T; cin>>S>>T;
	for(int i=0; i<N; i++) {
		string a;
		double b,c;
		cin>>a>>b>>c;
		m[a] = i;
		coords[i] = make_pair(b,c);
	}
	Graph G(N);
	for(int i=0; i<M; i++) {
		string s,t; cin>>s>>t;
		int a = m[s];
		int b = m[t];
		double distance = greatcircle(coords[a].first, coords[a].second, coords[b].first, coords[b].second, 6381) + 100;
		G.add_edge(a, b, distance);
		G.add_edge(b, a, distance);
	}

	vector<double> D(N);
	vector<int> P(N);
	dijkstra(G, m[S], D, P);
	cout<<setprecision(14)<<D[m[T]]<<endl;
}
