#include <bits/stdc++.h>
using namespace std;

double score(vector<int> v) {
    int n = v.size();
    double sum=0.0;
    for(int i=0; i<n; i++) {
        sum += (v[i] * pow(0.8, i));
    }
    return sum * 0.2;
}

int main() {
    int n; cin>>n;

    vector<int> v;
    for(int i=0; i<n; i++) {
        int temp; cin>>temp;
        v.push_back(temp);
    }

    double regScore = score(v);

    double sum=0.0;
    for(int i=0; i<v.size(); i++) {
        double temp = v[i];
        v.erase(v.begin()+i);
        sum += score(v);
        v.insert(v.begin()+i, temp);
    }

    cout<<setprecision(numeric_limits<double>::max_digits10)<<showpoint<<regScore<<endl<<setprecision(numeric_limits<double>::max_digits10)<<showpoint<<sum/v.size()<<endl;
}