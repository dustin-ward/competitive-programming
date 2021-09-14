#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,B,H,W; cin>>N>>B>>H>>W;

    int minPrice = B+1;
    for(int i=0; i<H; i++) {
        int price; cin>>price;

        for(int j=0; j<W; j++) {
            int cap; cin>>cap;

            if(cap >= N && N * price < minPrice)
                minPrice = N * price;
        }
    }

    if(minPrice <= B)
        cout<<minPrice<<endl;
    else
        cout<<"stay home"<<endl;
}