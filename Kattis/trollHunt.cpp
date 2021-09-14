#include <bits/stdc++.h>

using namespace std;

int main() {
    int b, k, g;
    cin>>b>>k>>g;
    int groups = k/g;
    int days = b/groups;

    cout<<days<<endl;
    return 0;
}
