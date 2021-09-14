#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 26;
const int DISCONNECT = -1;

/* assume that D and P have been allocated */
void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src, int D[], 
	      int P[])
{
  char used[MAX_NODES];
  int fringe[MAX_NODES];
  int f_size;
  int v, w, j, wj;
  int best, best_init;

  f_size = 0;
  for (v = 0; v < n; v++) {
    if (graph[src][v] != DISCONNECT && src != v) {
      D[v] = graph[src][v];
      P[v] = src;
      fringe[f_size++] = v;
      used[v] = 1;
    } else {
      D[v] = DISCONNECT;
      P[v] = -1;
      used[v] = 0;
    }
  }
  D[src] = 0;
  P[src] = -1;
  used[src] = 1;

  best_init = 1;
  while (best_init) {
    /* find unused vertex with smallest D */
    best_init = 0;
    for (j = 0; j < f_size; j++) {
      v = fringe[j];
      assert(D[v] != DISCONNECT);
      if (!best_init || D[v] < best) {
        best = D[v];
        w = v;
        wj = j;
        best_init = 1;
      }
    }

    if (best_init) {
      assert(D[w] != DISCONNECT);
      assert(fringe[wj] == w);

      /* get rid of w from fringe */
      f_size--;
      for (j = wj; j < f_size; j++) {
        fringe[j] = fringe[j+1];
      }

      /* update distances and add new vertices to fringe */
      for (v = 0; v < n; v++) {
        if (v != src && graph[w][v] != DISCONNECT) {
          if (D[v] == DISCONNECT || D[w] + graph[w][v] < D[v]) {
            D[v] = D[w] + graph[w][v];
            P[v] = w;
          } else if (D[w] + graph[w][v] == D[v]) {
            /* put tie-breaker here */
          }
          if (!used[v]) {
            used[v] = 1;
            fringe[f_size++] = v;
          }
        }
      }
    }
  }
  D[src] = 0;
}

int main() {
    int caseno=1;
    int T; cin>>T;
    while(T--) {
        int G[MAX_NODES][MAX_NODES], 
            D[MAX_NODES][MAX_NODES], 
            P[MAX_NODES][MAX_NODES];

        for(int i=0; i<MAX_NODES; i++) {
            for(int j=0; j<MAX_NODES; j++)
                G[i][j] = DISCONNECT;
        }

        string S; cin>>S;
        int K; cin>>K;
        for(int i=0; i<K; i++) {
            char a,b; cin>>a>>b;
            G[a-'A'][b-'A'] = 1;
        }
        for(int i=0; i<MAX_NODES; i++)
            dijkstra(G, MAX_NODES, i, D[i], P[i]);

        int minAns = INT_MAX;
        for(int i='A'; i<='Z'; i++) {
            int x=0;
            bool possible = true;
            for(char c:S) {
                if(c == i) continue;
                if(D[c-'A'][i-'A'] != DISCONNECT)
                    x += D[c-'A'][i-'A'];
                else {
                    possible = false;
                    break;
                }
            }
            if(possible)
                minAns = min(minAns, x);
        }

        cout<<"Case #"<<caseno++<<": "<<((minAns != INT_MAX) ? minAns : -1)<<endl;
    }
}