#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> v;
    long long n;
    while(cin>>n)
        v.push_back(n);

    for(long long i:v) {
        for(long long j:v) {
            for(long long k:v) {
                if (i + j +k == 2020) {
                    cout<<"ANSWER: "<<i*j*k<<endl;
                    return 0;
                }
            }
        }
    }
}