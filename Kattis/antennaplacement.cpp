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

FILE *in, *out;

/* change these as necessary */
#define MAXU 600
#define MAXV 600

#define U(i) (i)
#define V(i) ((i) + MAXU)
#define isU(i) ((i) < MAXU)
#define isV(i) ((i) >= MAXU)

#define isMatched(i) (isU(i) ? flagUmatched[(i)] : flagVmatched[(i)-MAXU])
#define isUsed(i) (isU(i) ? flagUused[(i)] : flagVused[(i)-MAXU])
#define isVisited(i) (isU(i) ? flagUvisited[(i)] : flagVvisited[(i)-MAXU])

#define setMatched(i) (isU(i)?(flagUmatched[(i)]=1):(flagVmatched[(i)-MAXU]=1))
#define setUsed(i) (isU(i)?(flagUused[(i)]=1):(flagVused[(i)-MAXU]=1))
#define setVisited(i) (isU(i)?(flagUvisited[(i)]=1):(flagVvisited[(i)-MAXU]=1))

char bipgraph[MAXU][MAXV];
int matching[MAXU]; /* matching[u] == v, _not_ plus MAXU */
char flagUmatched[MAXU], flagVmatched[MAXV];
char flagUvisited[MAXU], flagVvisited[MAXV];
char flagUused[MAXU],    flagVused[MAXV];
int predecessor[MAXU+MAXV], bqueue[MAXU+MAXV];

/* u and v are the number of vertices in sets U, and V, respectively,
 * filling up bipgraph[0..u-1][0..v-1].
 * result:
 *  matching[u0]==v0 iff u0 and v0 are in the matching, 
 * otherwise matching[u0] = -1 */
void
match(int u, int v) {
  int i,j, head,tail, bad, last, increased;

  for( i = 0; i < u; i++ ) {
    matching[i] = -1;
    flagUmatched[i] = 0;
  }
  for( i = 0; i < v; i++ ) flagVmatched[i] = 0;

  do { /* find alternating paths by repeated bfs. */
    for( i = 0; i < MAXU+MAXV; i++ ) predecessor[i] = -1;
    for( i = 0; i < MAXU; i++ ) flagUused[i] = flagUvisited[i] = 0;
    for( i = 0; i < MAXV; i++ ) flagVused[i] = flagVvisited[i] = 0;
  
    head = tail = 0;

    /* put all the unmatched u's on the queue. They start the 
     * alternating path. */
    for( i = 0; i < u; i++ ) {
      if( ! isMatched(U(i))) {
	bqueue[tail++] = U(i);
	predecessor[i] = -1; /* redundant statement */
	setVisited(U(i));
      }
    }

    /* flag that at least one path was found by the bfs.
     * when the bfs does not find an alternating path we are done. */
    increased = 0;

    while( head != tail ) {
      i = bqueue[head++];

      /* this node appeared on some previously found alternating path. */
      if( isUsed(i) ) continue;
    
      if( isV(i) && !isMatched(i) ) {
	/* we got to the end of an alternating path. see if
	 * it is disjoint with other paths found so far. only
	 * then can we mess it up a bit. */
	bad = 0;
	for( j = i; j != -1; j = predecessor[j]) {
	  if( isUsed(j)) {
	    bad = 1;
	    break;
	  }
	}
	
	if( ! bad ) {
	  /* this path is pristine. switch "polarity" of edges
	   * in the matching on this path. */

	  /* flag and instrumention - whether (not) to quit,
	   * and how many paths we found this bfs. */
	  increased++; 
	  for( j = i; j != -1; last = j, j = predecessor[j] ) {
	    if( isV(j) && !isMatched(j)) {
	      /* the only unmatched v - actually this means we
	       * are on the first iteration of this loop. */
	      setMatched(j);

	    } else if( isU(j) ) {
	      if( isMatched(j) ) {
		/* the node we saw in the previous iteration of
		 * this loop must be a V. We will match with it
		 * instead of the one we used to match with, which
		 * must be the next node visited in this loop. */
		assert(isV(last));
		matching[j] = last - MAXU;
	      } else {
		/* we are the very first u, one of the ones the
		 * bfs queue was "seeded" with. We should have ...*/
		assert(predecessor[j] == -1);
		setMatched(j);
		assert(isV(last));
		matching[j] = last - MAXU;
	      }
	    }
	    setUsed(j); /* this node cannot be used for other
			 * paths we might run across in the future
			 * on this bfs. */
	  } /* for */
	} /* if ! bad */
      } /* isV and !isMatched */

      else if( isV(i) ) {
	/* this must be a matched V - find the matching U and put it on 
	 * the queue if it is not visited or used. */

	bad = 1;

	for( j = 0; j < u; j++ ) {
	  if( isMatched(U(j)) && matching[j] == i - MAXU ) {
	    /* this is the one. */
	    if( ! isVisited(U(j)) && !isUsed(U(j))) {
	      setVisited(U(j));
	      bqueue[tail++] = U(j); 
	      predecessor[U(j)] = i;
	    }
	    bad = 0;
	    break;
	  }
	}
	assert(!bad);
      } /* isV */
      else if( isU(i) ) {
	/* we are at U. whether it is unmatched (a "seed"),
	 * or matched, we do the same thing - put on the queue
	 * all V's which it is connected to in the graph but
	 * which it is _not_ paired to in the current matching. */

	for( j = 0; j < v; j++ ) {
	  if( bipgraph[i][j] &&
	      !isVisited(V(j)) && 
	      !isUsed(V(j)) && 
	      matching[i] != j ) {
	    /* we can put this one on the queue. */
	    bqueue[tail++] = V(j);
	    predecessor[V(j)] = i;
	    setVisited(V(j));
	  }
	}
      } else {
	assert(0); /* should be no other cases. */
      }
      /* this is the end of the bfs. */
    } 
  } while( increased );

  return;
}

int dy[4] = {0,-1,0,1};
int dx[4] = {-1,0,1,0};
int N,M;

bool bounds(int i, int j) {
	return i >= 0 && i < N && j >= 0 && j < M;
}

int getNode(int i, int j) {
	return (i*M)+j;
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>N>>M;
		int U,V; U = V = (N*M);
		
		for(int i=0; i<U; ++i)
			for(int j=0; j<V; ++j)
				bipgraph[i][j] = 0;

		int count = 0;
		vector<vector<char>> B(N, vector<char>(M));
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				cin>>B[i][j];
				if(B[i][j] == '*')
					count++;
			}
		}
	
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				if(B[i][j] != '*' || (i+j)%2) continue;
				for(int k=0; k<4; ++k) {
					int i2 = i+dy[k];
					int j2 = j+dx[k];
					if(bounds(i2,j2) && B[i2][j2] == '*') {
						bipgraph[getNode(i,j)][getNode(i2,j2)] = 1;
					}
				}
			}
		}
	
		match(U,V);
		for(int i=0; i<U; ++i) {
			if(matching[i]>=0)
				count--;
		}
		cout<<count<<endl;
	}
}
