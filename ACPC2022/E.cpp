#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,M;

ll f(ll a, ll b) {
	ll ans = 0;
	ll za = min(N,__builtin_ctzll(a));
	ll zb = min(N,__builtin_ctzll(b));
	if(za > zb) {
		ans += za-zb;
		b = b << (za-zb);
	}
	else if(zb > za) {
		ans += zb-za;
		a = a << (zb-za);
	}
	ll c = a^b;
	ll zc = __builtin_ctzll(c);
	if(zc <= N) ans += (N-zc)*2;
	return ans;
}

int main() {
	cin>>N>>M;
	vector<ll> V(M);
	for(ll &i:V)
		cin>>i;
	
	ll ans = 0;
	for(int i=0; i<M-1; ++i)
		ans += f(V[i], V[i+1]);
	cout<<ans<<endl;
}
