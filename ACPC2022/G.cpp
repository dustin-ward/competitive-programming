#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; cin>>N;
	vector<int> V(N);
	for(int &i:V)
		cin>>i;

	map<int,int> M;
	for(int i=0; i<N; ++i) {
		int r = ((i+N)-(V[i]-1))%N;
		M[r]++;
	}

	int f = 0,k=-1;
	for(auto &p:M) {
		//cout<<p.first<<" "<<p.second<<endl;
		if(p.second > f) {
			f = p.second;
			k = p.first;
		}
	}
	assert(k != -1);
	cout<<k<<" "<<f<<endl;
}
