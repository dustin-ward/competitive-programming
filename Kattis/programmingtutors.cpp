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

// Unweighted Bipartite Matching (Undirected Only) -- O(m*sqrt(n))
//  -- Your match is stored in "mate". (mate == -1 if there is no match)
//  -- adj is an adjacency list that indexes the other set
//         Ex: U[0].adj[0] == x means there is an edge from U[0] to V[x]

struct Node{ vector<int> adj; int mate,pred; }; // Ignore "pred" -- For internal use.

void add_edge(Node U[],int u_node,Node V[],int v_node){
  U[u_node].adj.push_back(v_node);
  V[v_node].adj.push_back(u_node);  
}

// u is the number of elements in U
// v is the number of elements in V
int match(Node U[],int u,Node V[],int v){
  for(int i=0;i<u;i++) U[i].mate = -1;
  for(int i=0;i<v;i++) V[i].mate = -1;

  int numMatches = 0;
  while(true){
    queue<int> q1,q2;
    for(int i=0;i<u;i++) if(U[i].mate == -1) q1.push(i);
    for(int i=0;i<u;i++) U[i].pred = -1;
    for(int i=0;i<v;i++) V[i].pred = -1;

    while(!q1.empty()){
      int x = q1.front(); q1.pop();
      for(int i=0;i<U[x].adj.size();i++){ int w = U[x].adj[i];
	if(V[w].pred != -1) continue;
	if(V[w].mate == -1) V[w].pred = x , q2.push(w);
	else if(V[w].mate != x && U[V[w].mate].pred == -1)
	  V[w].pred = x , U[V[w].mate].pred = w , q1.push(V[w].mate); 
      }
    }

    if(q2.empty()) break;
    while(!q2.empty()){
      Node* W = V; int i,x = q2.front(); q2.pop();
      for(i = x;i >= 0;W=(W == U ? V : U)) i = W[i].pred;
      if(i == -2) continue; numMatches++;
      for(i = x;i >= 0;){
	int p = V[i].pred;  V[i].pred = -2;  V[i].mate = p;
	U[p].mate = i;      i = U[p].pred;   U[p].pred = -2;
      }
    }
  }
  return numMatches;
}

int N;
int D[101][101];
bool solve(int d) {
    Node U[101], V[101];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(D[i][j] <= d)
                add_edge(U, i, V, j);
        }
    }

    return match(U,N,V,N) == N;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>N;
    vpii S(N),T(N);
    for(int i=0; i<N; i++)
        cin>>S[i].first>>S[i].second;

    for(int i=0; i<N; i++)
        cin>>T[i].first>>T[i].second;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            D[i][j] = abs(S[i].first-T[j].first) + abs(S[i].second-T[j].second);
    }

    if(solve(0))
        cout<<0<<endl;
    else {
        int lo = 0;
        int hi = 1;
        while(!solve(hi))
            hi *= 2;

        while(hi-lo > 1) {
            int mid = lo + (hi-lo)/2;
            if(solve(mid))
                hi = mid;
            else
                lo = mid;
        }
        cout<<hi<<endl;
    }
}