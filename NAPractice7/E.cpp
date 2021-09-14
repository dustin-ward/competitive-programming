#include <bits/stdc++.h>
using namespace std;

// -5 -5 -5
// -2  0 -5
// -2 -2 -5
// 1 1


pair<int,int> d[8] = {{-1,-1}, {-1,0}, {-1, 1}, {0, -1}, {0,1}, {1,-1}, {1,0}, {1,1}};

int main() {
    int h,w; cin>>h>>w;
    vector<vector<int>> map(h, vector<int>(w));
    vector<vector<int>> visited(h, vector<int>(w, 0));

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            int temp; cin>>temp;
            map[i][j] = -temp;
        }
    }

    int i,j; cin>>i>>j;
    int startDepth = map[i-1][j-1];
    visited[i-1][j-1] = 1;

    long long ans = 0;
    priority_queue<pair<int, pair<int,int>>> q;
    q.push(make_pair(map[i-1][j-1], make_pair(i-1,j-1)));
    while(!q.empty()) {
        pair<int, pair<int,int>> p = q.top(); q.pop();
        startDepth = min(startDepth, map[p.second.first][p.second.second]);
        // cout<<"starting at "<<p.second.first<<" "<<p.second.second<<endl;
        if(map[p.second.first][p.second.second] >= startDepth) {
            // cout<<"adding "<<startDepth<<endl;
            ans += startDepth;
        }
        else {
            // cout<<"adding "<<map[p.second.first][p.second.second]<<endl;
            ans += map[p.second.first][p.second.second];
        }

        for(int di=0; di<8; di++) {
            int dx = p.second.first+d[di].first;
            int dy = p.second.second+d[di].second;
            // cout<<"considering "<<dx<<" "<<dy<<endl;
            if(dx < 0 || dx >= h) continue;
            if(dy < 0 || dy >= w) continue;
            if(map[dx][dy] <= 0) continue;
            if(visited[dx][dy]) continue;
            // cout<<"Added"<<endl;
            pair<int, pair<int,int>> p2 = make_pair(map[dx][dy], make_pair(dx, dy));
            q.push(p2);
            visited[dx][dy] = 1;
        }
    }

    cout<<abs(ans)<<endl;

}