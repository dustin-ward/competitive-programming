#include "vectorfunctions.h"

void backwards(std::vector<int>& vec){
    int l=0, r=vec.size()-1;
    while(l<r)
        std::swap(vec[l++], vec[r--]);
}

std::vector<int> everyOther(const std::vector<int>& vec){
    std::vector<int> V;
    for(int i=0; i<vec.size(); i+=2)
        V.push_back(vec[i]);
    return V;
}

int smallest(const std::vector<int>& vec){
    int ans = (1<<30)-1;
    for(int i:vec)
        ans = std::min(ans, i);
    return ans;
}

int sum(const std::vector<int>& vec){
    int i=0;
    for(auto &x:vec)
        i += x;
    return i;
}

int veryOdd(const std::vector<int>& suchVector){
    int ans = 0;
    for(int i=1; i<suchVector.size(); i+=2)
        if(suchVector[i]%2) ans++;
    return ans;
}