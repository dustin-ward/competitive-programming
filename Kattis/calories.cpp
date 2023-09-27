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

int main() {
    string line;
    while(getline(cin,line) && line != "-") {
        double totalC = 0;
        double totalF = 0;
        while(line != "-") {
            istringstream iss(line);

            int f,p,sg,st,a;
            char uf,up,usg,ust,ua;
            iss>>f>>uf>>p>>up>>sg>>usg>>st>>ust>>a>>ua;
            
            if(uf=='g') {
                f *= 9;
                uf = 'C';
            }
            if(up=='g') {
                p *= 4;
                up = 'C';
            }
            if(usg=='g') {
                sg *= 4;
                usg = 'C';
            }
            if(ust=='g') {
                st *= 4;
                ust = 'C';
            }
            if(ua=='g') {
                a *= 7;
                ua = 'C';
            }

            int C = 0;
            if(uf=='C') C += f;
            if(up=='C') C += p;
            if(usg=='C') C += sg;
            if(ust=='C') C += st;
            if(ua=='C') C += a;

            double P = 100;
            if(uf=='%') P -= f;
            if(up=='%') P -= p;
            if(usg=='%') P -= sg;
            if(ust=='%') P -= st;
            if(ua=='%') P -= a;

            double C2 = C / (P/100);
            totalC += C2;

            if(uf=='C') totalF += f;
            else totalF += C2 * ((double)f/100);
    
            /* debug(totalC); */
            /* debug(totalF); */
            getline(cin,line);
        }
        cout<<round(((double)totalF/totalC)*100)<<"%"<<endl;
    }
}
