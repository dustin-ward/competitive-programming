#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin,s);
	if(s.find(":)") != string::npos && s.find(":(") != string::npos)
		cout<<"double agent"<<endl;
	else if(s.find(":)") != string::npos)
		cout<<"alive"<<endl;
	else if(s.find(":(") != string::npos)
		cout<<"undead"<<endl;
	else
		cout<<"machine"<<endl;
}
