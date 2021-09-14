#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &v, vector<int> &abc, int N) {
    int infectedVax = 0, infectedControl = 0;
    int totalVax = 0, totalControl = 0;
    for(int i=0; i<N; i++) {
        if(v[i]) {
            totalVax++;
            infectedVax += abc[i];
        }
        else {
            totalControl++;
            infectedControl += abc[i];
        }
    }

    double controlRate = double(infectedControl)/double(totalControl);
    double infectedRate = double(infectedVax)/double(totalVax);

    if(infectedControl * totalVax <= infectedVax * totalControl)
        cout<<"Not Effective"<<endl;
    else {
        double ans = 100*(1.0 - infectedRate / controlRate);
        cout<<fixed<<setprecision(9)<<ans<<endl;
    }    
}

int main() {
    int N; cin>>N;
    vector<int> v(N), a(N), b(N), c(N);
    for(int i=0; i<N; i++) {
        string s; cin>>s;
        v[i] = (s[0] == 'Y');
        a[i] = (s[1] == 'Y');
        b[i] = (s[2] == 'Y');
        c[i] = (s[3] == 'Y');
    }

    f(v, a, N);
    f(v, b, N);
    f(v, c, N);
}