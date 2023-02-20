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

const int MAX_NODES = 100005;

struct Graph{
  int numNodes;
  vector<int> adj[MAX_NODES];
  void clear(){
    numNodes = 0;
    for(int i=0;i<MAX_NODES;i++)
      adj[i].clear();
  }
  void add_edge(int u,int v){
      adj[u].push_back(v);
  }
};

int po[MAX_NODES],comp[MAX_NODES];

void DFS(int v,const Graph& G,Graph& G_scc,int& C,
	 stack<int>& P,stack<int>& S){
  po[v] = C++;
  
  S.push(v);  P.push(v);
  for(unsigned int i=0;i<G.adj[v].size();i++){
    int w = G.adj[v][i];
    if(po[w] == -1){
      DFS(w,G,G_scc,C,P,S);
    } else if(comp[w] == -1){
      while(!P.empty() && (po[P.top()] > po[w]))
	P.pop();
    }
  }
  if(!P.empty() && P.top() == v){
    while(!S.empty()){
      int t = S.top();
      S.pop();
      comp[t] = G_scc.numNodes;
      if(t == v)
	break;
    }
    G_scc.numNodes++;
    P.pop();
  }
}

int SCC(const Graph& G,Graph& G_scc){
  G_scc.clear();
  int C=1;
  stack<int> P,S;
  fill(po,po+G.numNodes,-1);
  fill(comp,comp+G.numNodes,-1);
  for(int i=0;i<G.numNodes;i++)
    if(po[i] == -1)
      DFS(i,G,G_scc,C,P,S);
  
  // You do not need this if you are only interested in the number of
  //    strongly connected components.
  for(int i=0;i<G.numNodes;i++){
    for(unsigned int j=0;j<G.adj[i].size();j++){
      int w = G.adj[i][j];
      if(comp[i] != comp[w])
	G_scc.add_edge(comp[i],comp[w]);
    }
  }
  
  return G_scc.numNodes;
}

const ll MOD = 1E9+7;
Graph G,G_scc,G_rev;

ll f(int i) {
    ll ans = 1;
    for(int g:G_rev.adj[i])
        ans = (ans * f(g)) % MOD;
    // cout<<"f("<<i<<") = "<<ans+1<<endl;
    return (ans + 1) % MOD;
}

ll g(int c) {
    ll ans = 1;
    for(int j:G_rev.adj[c])
        ans = (ans * f(j)) % MOD;
    // cout<<"g("<<c<<") = "<<ans+1<<endl;
    return (ans+1) % MOD;
}

int main() {
    int N; cin>>N;
    G.numNodes = N;
    for(int i=0; i<N; ++i) {
        int temp; cin>>temp;
        G.add_edge(i,temp-1);
    }
    SCC(G,G_scc);

    // cout<<"SCC Graph ========="<<endl;
    // for(int i=0; i<G_scc.numNodes; ++i) {
    //     for(int j:G_scc.adj[i])
    //         cout<<i<<" -> "<<j<<endl;
    // }
    
    G_rev.numNodes = G_scc.numNodes;
    for(int i=0; i<G_scc.numNodes; ++i) {
        for(int j:G_scc.adj[i])
            G_rev.add_edge(j,i);
    }

    ll ans = 1;
    for(int i=0; i<G_rev.numNodes; ++i) {
        if(!sz(G_scc.adj[i]))
            ans = (ans * g(i)) % MOD;
    }

    cout<<(ans+MOD-1)%MOD<<endl;
}
