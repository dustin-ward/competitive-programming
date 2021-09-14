#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int E = 1000000007;

int main() {
    int T, caseno=1; cin>>T;
    while(T--) {
        int N,K,W; cin>>N>>K>>W;
        vector<ll> L(N), H(N), P(N);
        
        // Build L array
        for(int i=0; i<K; i++)
            cin>>L[i];
        ll Al,Bl,Cl,Dl; cin>>Al>>Bl>>Cl>>Dl;
        for(int i=K; i<N; i++)
            L[i] = ((Al * L[i-2] + Bl * L[i-1] + Cl) % Dl) + 1;
    
        // Build H array
        for(int i=0; i<K; i++)
            cin>>H[i];
        ll Ah,Bh,Ch,Dh; cin>>Ah>>Bh>>Ch>>Dh;
        for(int i=K; i<N; i++)
            H[i] = ((Ah * H[i-2] + Bh * H[i-1] + Ch) % Dh) + 1;
    
        // Determine starting room perimeter
        P[0] = 2*H[0] + 2*W;

        for(int i=1; i<N; i++) {
            // int lastPos;
            // if(i>1 && L[i] <= L[i-2]+W && H[i-1] <= min(H[i-2],H[i]))
            //     lastPos = i-2;
            // else
            //     lastPos = i-1;
            
            // Keep checking rooms backwards until you find one that will actually add new parimeter
            int lastPos = i-1;
            while(lastPos>0 && L[lastPos] <= L[lastPos-1]+W && L[lastPos+1] <= L[lastPos-1]+W && H[lastPos] <= min(H[lastPos-1], H[lastPos+1])) {
                lastPos--;
            }

            // Add perimeter of new room to total
            ll tempP = P[lastPos];
            if(L[i] > L[lastPos]+W) {
                // Room is detached
                tempP += 2*H[i] + 2*W;
            }
            else {
                // Room has some amount of overlap
                tempP -= H[lastPos];
                ll overlap = (L[lastPos] + W) - L[i];
                tempP += 2*(W-overlap) + abs(H[i] - H[lastPos]) + H[i];
            }
            P[i] = tempP;
        }

        cout<<"L:"<<endl;
        for(auto i:L)
            cout<<i<<" ";
        cout<<endl;

        cout<<"H:"<<endl;
        for(auto i:H)
            cout<<i<<" ";
        cout<<endl;

        cout<<"P:"<<endl;
        for(auto i:P)
            cout<<i<<" ";
        cout<<endl;

        // Product of perimeters mod E
        ll ans=1;
        for(auto i:P)
            ans = (ans * i) % E;
        cout<<"Case #"<<caseno++<<": "<<ans<<endl;
    }
}