#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<int> m1;
vector<int> m2;

bool isTranspositon() {
    int diff = m2[0] - m1[0];
    vector<int> tempM2 = m2;

    for(int i=0; i<tempM2.size(); i++) {
        tempM2[i] = (tempM2[i] - diff);
        if(tempM2[i] <= 0) tempM2[i] += 12;
        if(tempM2[i] > 12) tempM2[i] -= 12;
        if(tempM2[i] != m1[i])
            return false;
    }
    return true;
}

bool isRetrograde() {
    vector<int> tempM2 = m2;
    reverse(tempM2.begin(), tempM2.end());

    for(int i=0; i<m1.size(); i++) {
        if(m1[i] != tempM2[i])
            return false;
    }
    return true;
}

bool isInversion() {
    int start = m1[0];
    vector<int> tempM2 = m2;
    if(m1[0]!=m2[0])
        return false;

    for(int i=1; i<m1.size(); i++) {
        if(m1[i]==start)
            continue;
        int diff = m1[i] - start;
        int x = start - diff;
        if(x <= 0) x+=12;
        if(x > 12) x-=12;
        if(m2[i]!=x)
            return false;
    }
    return true;
}   

int main() {
    m.insert(make_pair("C", 1));
    m.insert(make_pair("C#", 2));
    m.insert(make_pair("D", 3));
    m.insert(make_pair("D#", 4));
    m.insert(make_pair("E", 5));
    m.insert(make_pair("F", 6));
    m.insert(make_pair("F#", 7));
    m.insert(make_pair("G", 8));
    m.insert(make_pair("G#", 9));
    m.insert(make_pair("A", 10));
    m.insert(make_pair("A#", 11));
    m.insert(make_pair("B", 12));
    int l; cin>>l;

    for(int i=0; i<l; i++) {
        string temp; cin>>temp;
        m1.push_back(m[temp]);        
    }

    for(int i=0; i<l; i++) {
        string temp; cin>>temp;
        m2.push_back(m[temp]);
    }

    if(isTranspositon())
        cout<<"Transposition"<<endl;
    else if(isRetrograde())
        cout<<"Retrograde"<<endl;
    else if(isInversion())
        cout<<"Inversion"<<endl;
    else
        cout<<"Nonsense"<<endl;
    
}