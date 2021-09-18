#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    vector<int> palindromes;
    for(int i=100; i<1000; i++) {
        string front = to_string(i);
        string back = front;
        reverse(back.begin(), back.end());
        palindromes.push_back(stoi(front+back));
    }

    for(int i=0; i<N; i++) {
        int bestDif = 1000000;
        int num; cin>>num;
        int ans = num;
        for(int j=0; j<palindromes.size(); j++) {
            if(abs(palindromes[j]-num) < bestDif) {
                bestDif = abs(palindromes[j]-num);
                ans = palindromes[j];
            }
        }
        cout<<ans<<endl;
    }
}