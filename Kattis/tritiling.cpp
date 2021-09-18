#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if(n == 0)
        return 1;
    if(n == 1)
        return 0;
    return f(n-2) + (2 * g(n-1));
}

int g(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return f(n-1) + g(n-2);
}

int main() {
    int temp;
    cin>>temp;
    while(temp != -1) {
        cout<<f(temp)<<endl;
        cin>>temp;
    }

}