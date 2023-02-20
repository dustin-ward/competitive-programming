#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,D;
ll dp[10001][2];
ll H[10002], E[10002];

ll f(int pos, int c, int e) {
	if(pos == N)
		return 0;
	if(dp[pos][c] != -1)
		return dp[pos][c];

	ll x1 = max((ll)0, (H[pos] - e + D - 1  - E[pos+1]) / D);
	ll x2 = max((ll)0, (H[pos] - e + D - 1) / D);
	return dp[pos][c] = min(x1 + f(pos+1,0,0), x2 + f(pos+1,1,E[pos])); 
}

int main() {
	int T; cin>>T;
	while(T--) {
		cin>>N>>D;
		for(int i=0; i<N; i++) {
			dp[i][0] = dp[i][1] = -1; 	
			cin>>H[i];
		}
		for(int i=0; i<N; i++)
			cin>>E[i];
		H[N] = E[N] = 0;
		cout<<f(0,0,0)<<endl;		
	}

}
