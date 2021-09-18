#include <bits/stdc++.h>
using namespace std;

int main() {
    int s,t,n; cin>>s>>t>>n;

    queue<int> walkTimes;
    for(int i=0; i<=n; i++) {
        int temp; cin>>temp;
        walkTimes.push(temp);
    }

    queue<int> transitTimes;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        transitTimes.push(temp);
    }

    queue<int> busTimes;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        busTimes.push(temp);
    }

    int curTime=s;
    bool madeIt = false;
    int busNo = 0;
    while(true) {
        if(curTime > t)
            break;

        curTime += walkTimes.front(); walkTimes.pop();

        while(curTime%busTimes.front() != 0)
            curTime++;
        busTimes.pop();

        curTime += transitTimes.front(); transitTimes.pop();

        if(transitTimes.empty()) {
            curTime += walkTimes.front();
            if(curTime <= t)
                madeIt = true;
            break;
        }
    }

    if(!madeIt)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
}