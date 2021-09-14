// Binary Search
#include <bits/stdc++.h>
using namespace std;

int finalX, finalY;
vector<tuple<int,int,double>> sheilds;

bool check(double v) {
    
}

int main() {
    int n;
    cin>>finalX>>finalY>>n;

    for(int i=0; i<n; i++) {
        int l,u; cin>>l>>u;
        double f; cin>>f;

        sheilds.push_back(make_tuple(l,u,f));
    }


}