#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int ng, nm; cin>>ng>>nm;
        priority_queue<int> g, m;
        for(int i=0; i<ng; i++) {
            int temp; cin>>temp;
            g.push(-temp);
        }
        for(int i=0; i<nm; i++) {
            int temp; cin>>temp;
            m.push(-temp);
        }

        while(!g.empty() && !m.empty()) {
            if(-g.top() < -m.top())
                g.pop();
            else
                m.pop();
        }

        if(g.empty())
            cout<<"MechaGodzilla"<<endl;
        else
            cout<<"Godzilla"<<endl;
        
    }
}