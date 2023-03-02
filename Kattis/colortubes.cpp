#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define fst first
#define snd second
#define debug(a) cerr << #a << " = " << (a) << endl;
#define sz(x) (int)(x).size()
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)

const double PI = acos(-1);
double time() { return double(clock()) / CLOCKS_PER_SEC; }

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.fst << ", " << x.snd << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

int N;
vector<vi> T;
vpii ans;

void printTubes() {
    cout<<"================"<<endl;
    for(int i=0; i<N+1; i++) {
        for(int j=0; j<3; j++)
            cout<<T[i][j]<<" ";
        cout<<endl;
    }
    cout<<"================"<<endl;
}

void reset() {
    // printTubes();
    for(int i=2; i>=0; i--) {
        if(T[N][i]) {
            bool swapped = false;
            for(int j=0; j<N; j++) {
                for(int k=0; k<3; k++) {
                    if(T[j][k]==0) {
                        swap(T[N][i],T[j][k]);
                        ans.emplace_back(N+1,j+1);
                        swapped = true;
                        break;
                    }
                }
                if(swapped) break;
            }
        }
    }
    // printTubes();
}

int main() {
    cin>>N;
    T.resize(N+1, vi(3));
    for(vi &v:T)
        for(int &i:v)
            cin>>i;

    reset();

    for(int t=0; t<N; t++) {
        int c = T[t][0];

        // Middle
        bool mid = false;
        if(T[t][1]!=c) {
            // Make space in tube t
            // Move top to e
            swap(T[t][2],T[N][0]);
            ans.emplace_back(t+1,N+1);
            // Move mid to e
            swap(T[t][1],T[N][1]);
            ans.emplace_back(t+1,N+1);
            assert(T[t][1]==0);

            // Find replacement
            for(int i=t+1; i<N; i++) {
                for(int j=0; j<3; j++) {
                    if(T[i][j]==c) {
                        // Top
                        if(j==2) {
                            swap(T[t][1],T[i][2]);
                            ans.emplace_back(i+1,t+1);
                            mid=true;
                            break;
                        }

                        // Middle
                        if(j==1) {
                            // Move Top
                            swap(T[i][2],T[N][2]);
                            ans.emplace_back(i+1,N+1);
                            // Move middle
                            swap(T[i][1],T[t][1]);
                            ans.emplace_back(i+1,t+1);
                            mid = true;
                            break;
                        }

                        // Bottom
                        if(j==0) {
                            // Move Top to t
                            swap(T[i][2],T[t][1]);
                            ans.emplace_back(i+1,t+1);
                            
                            // Move middle to t
                            swap(T[i][1],T[t][2]);
                            ans.emplace_back(i+1,t+1);

                            // Move bottom to e
                            swap(T[i][0],T[N][2]);
                            ans.emplace_back(i+1,N+1);

                            // Move top t to i
                            swap(T[t][2],T[i][0]);
                            ans.emplace_back(t+1,i+1);

                            // Move mid t to i
                            swap(T[t][1],T[i][1]);
                            ans.emplace_back(t+1,i+1);

                            // Move e to t
                            swap(T[N][2],T[t][1]);
                            ans.emplace_back(N+1,t+1);
                            mid = true;
                            break;
                        }
                    }
                }
                if(mid) break;
            }
            reset();
        }
        
        // Top
        bool top = false;
        if(T[t][2]!=c) {
            // Make space in tube t
            // Move top to e
            swap(T[t][2],T[N][0]);
            ans.emplace_back(t+1,N+1);
            assert(T[t][2]==0);

            // Find replacement
            for(int i=t+1; i<N; i++) {
                for(int j=0; j<3; j++) {
                    if(T[i][j]==c) {
                        // Top
                        if(j==2) {
                            swap(T[t][2],T[i][2]);
                            ans.emplace_back(i+1,t+1);
                            top=true;
                            break;
                        }

                        // Middle
                        if(j==1) {
                            // Move Top
                            swap(T[i][2],T[N][1]);
                            ans.emplace_back(i+1,N+1);
                            // Move middle
                            swap(T[i][1],T[t][2]);
                            ans.emplace_back(i+1,t+1);
                            top = true;
                            break;
                        }

                        // Bottom
                        if(j==0) {
                            // Move Top to e
                            swap(T[i][2],T[N][1]);
                            ans.emplace_back(i+1,N+1);
                            
                            // Move middle to e
                            swap(T[i][1],T[N][2]);
                            ans.emplace_back(i+1,N+1);

                            // Move bottom to t
                            swap(T[i][0],T[t][2]);
                            ans.emplace_back(i+1,t+1);
                            top = true;
                            break;
                        }
                    }
                }
                if(top) break;
            }
            reset();
        }
    }


    cout<<sz(ans)<<endl;
    for(auto &p:ans)
        cout<<p.fst<<" "<<p.snd<<endl;

    // printTubes();
}
