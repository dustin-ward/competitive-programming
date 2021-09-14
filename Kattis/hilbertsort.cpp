#include <bits/stdc++.h>

using namespace std;                                                            

typedef long long ll;
typedef pair<ll, ll> pii;                                                      
                                                                                
void f(vector<pii>& P, ll l, ll r, ll t, ll b) {                            
  if(l == r || P.size() == 0)                                                                  
        return;                                                                 

    ll midX = (l+r)/2;                                                         
    ll midY = (b+t)/2;                                                         
                                                                                
    vector<pii> Q[4];                                                           
                                                                                
    for(int i=0; i<P.size(); i++) {                                             
        if(P[i].first > midX) {                                                 
            if(P[i].second > midY)                                              
                Q[2].push_back(P[i]);                                           
            else {                                                              
	            Q[3].push_back(make_pair(r+b-P[i].second, r+b-P[i].first)); 
            }                                                                   
        }                                                                       
        else { // P[i].first <= midX                                            
            if(P[i].second > midY)                                              
                Q[1].push_back(P[i]);                                           
            else {                                                              
                ll x=(P[i].second-b)+l;                                        
                ll y=(P[i].first-l)+b;                                         
                Q[0].push_back(make_pair(x, y));                                
            }                                                                   
        }                                                                       
    }                                                                           
                                                                                
    if(!Q[0].empty())                                                           
        f(Q[0], l, midX, midY, b);                                              
    if(!Q[1].empty())                                                           
        f(Q[1], l, midX, t, midY+1);                                            
    if(!Q[2].empty())                                                           
        f(Q[2], midX+1, r, t, midY+1);                                          
    if(!Q[3].empty())                                                           
        f(Q[3], midX+1, r, midY, b);                                            
                                                                                
    // Convert Back                                                             
    for(pii &i:Q[0]) {                                                           
        ll t1=i.first, t2=i.second;                                            
        i.first = (t2-b)+l;                                                     
        i.second = (t1-l)+b;                                                    
    }                                                                           
                                                                                
    for(pii &i:Q[3]) {                                                           
        ll t1=i.first, t2=i.second;                                            
        i.first = r+b-t2;                                                     
        i.second = r+b-t1;                                                    
    }                                                                           
                                                                                
    int idx = 0;                                                                
    for(int i=0; i<4; i++) {                                                    
        for(auto p:Q[i]) {                                                      
            P[idx++] = p;                                                       
        }                                                                       
    }                                                                           
}                                                                               
                                                                                
const int S = 30;

int main() {                                                                    
    ll n,s; cin>>n>>s;                                                         
    vector<pii> P;                                                              
                                                                                
    for(int i=0; i<n; i++) {                                                    
        ll x,y; cin>>x>>y;                                                     
        P.emplace_back(x << S, y << S);                                                    
    }                                                                           
                                                                                
    f(P,0,(s << S),(s << S),0);                                                               
                                                                                
    // cout<<"ANSWER"<<endl;                                                    
    for(pii i:P)                                                                
      cout<<(i.first >> S)<<" "<< (i.second >> S)<<endl;                                     
}                                                                               
                                                                                
                                
