#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1,h2,m1,m2;
    char c;
    cin>>h1>>c>>m1;
    cin>>h2>>c>>m2;

    int time1 = h1*60+m1;
    int time2 = h2*60+m2;

    int mid = (time1+time2) / 2;

    cout<<setw(2)<<setfill('0')<<mid/60<<":"<<setw(2)<<setfill('0')<<mid%60<<endl;
}