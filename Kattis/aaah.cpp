#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2; cin>>s1>>s2;

	int a1 = s1.find('h');
	int a2 = s2.find('h');

	cout<<((a1 >= a2) ? "go" : "no")<<endl;
}
