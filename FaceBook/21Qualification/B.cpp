#include <bits/stdc++.h>
using namespace std;

int main() {
    int caseno=1;
    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<vector<char>> G(N, vector<char>(N));
        priority_queue<pair<int,long long>> pq;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++)
                cin>>G[i][j];
        }

        for(int i=0; i<N; i++) {
            long long x = 0;
            int num = 0;
            bool possible = true;
            for(int j=0; j<N; j++) {
                if(G[i][j] == 'O') {
                    possible = false;
                    break;
                } else if (G[i][j] == '.') {
                    x |= 1 << ((i*N) + j);
                    num++;
                }
            }

            if(possible) {
                pq.push(make_pair(-num, x));
            }
        }

        for(int i=0; i<N; i++) {
            long long x = 0;
            int num = 0;
            bool possible = true;
            for(int j=0; j<N; j++) {
                if(G[j][i] == 'O') {
                    possible = false;
                    break;
                } else if (G[j][i] == '.') {
                    x |= 1 << ((j*N) + i);
                    num++;
                }
            }

            if(possible) {
                pq.push(make_pair(-num, x));
            }
        }

        cout<<"Case #"<<caseno++<<": ";
        if(pq.empty()) {
            cout<<"Impossible"<<endl;
            continue;
        }

        set<long long> s;
        int sz = -pq.top().first;
        int num = 0;
        while(-pq.top().first == sz && !pq.empty()) {
            cout<<"TOP "<<-pq.top().first<<" "<<pq.top().second<<endl;
            if(s.find(pq.top().second) == s.end()) {
                s.insert(pq.top().second);
                num++;
            }
            pq.pop();
        }

        cout<<sz<<" "<<num<<endl;
    }
}