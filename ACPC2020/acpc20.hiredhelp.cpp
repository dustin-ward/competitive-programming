#include<bits/stdc++.h>
using namespace std;

int N,K;
vector<int> v;

bool f(int n) {
	vector<int> J(n, 0), L(n, 0);

	int index = 0;

	for (int k = 0; k < K; k++) {
		for (int i = 0; i < n; i++) {
			while (index < N && L[i] >= v[index])
				index++;
			if (index < N) {
				J[i]++;
				L[i]++;
				index++;
			} 
			else
				return false;
		}
	}
	return true;
}

int main() {
	cin>>N>>K;
	v.resize(N);
	for(int &x:v)
		cin>>x;

	sort(v.begin(), v.end());
	
	int lo=0, hi=(N/K)+1, mid;
	while(hi-lo > 1) {
		mid = (lo+hi)/2;
		// cout<<"lo: "<<lo<<" mid: "<<mid<<" hi: "<<hi<<endl;
		if(f(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout<<lo<<endl;
}
