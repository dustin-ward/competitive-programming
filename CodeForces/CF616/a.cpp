#include <bits/stdc++.h>
using namespace std;

long long sumFunc(long long n) {
    long long sum=0, m;
    while(n>0){
        m=n%10;
        sum=sum+m;
        n=n/10;
    }
    return sum;
}

void removeDigit(string s) {
    for(int i=s.length()-1; i>=0; i--) {
        if(s.length() == 1) {
            cout<<-1<<endl;
            return;
        }
        
        s.erase(s.begin()+i);

        long long x;
        istringstream iss(s);
        iss>>x;

        if(x % 2 != 0 && sumFunc(x) % 2 == 0) {
            cout<<x<<endl;
            return;
        }
    }
}

int main() {
    int c;
    cin>>c;

    while(c--) {
        long long n;
        string s1;
        cin>>n>>s1;

        while(s1.length() >= 20) {
            s1 = s1.substr(0, s1.length()-2);
        }

        long long s = stoll(s1);

        if(s % 2 != 0 && sumFunc(s) % 2 == 0) {
            cout<<s<<endl;
            continue;
        }

        string s2 = to_string(s);

        removeDigit(s2);
        
    }
}