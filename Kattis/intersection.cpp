#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<int> C;
    vector<int> A = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    vector<int> B = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int indexA = 0, indexB = 0;
	while(indexA < n && indexB < n) {
		if(A[indexA] == B[indexB]) {
			C.push_back(A[indexA]);
			indexA++;
			indexB++;
        }
		else if(A[indexA] > B[indexB]) {
			indexB++;
        }
		else {
			indexA++;
        }
    }

    for(auto i:C)
        cout<<i<<" ";
    cout<<endl;
}
