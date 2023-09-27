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
	int T; cin>>T;
	while(T--) {
		int N; cin>>N;
		vi A(N);
		for(int i=0; i<N; i++)
			cin>>A[i];
		
		int maxElem = 0;
		int maxVal = 0;
		for(int i=1; i<N; i++) {
			if(A[i]>maxVal) {
				maxVal = A[i];
				maxElem = i;
			}
		}

		int j;
		if(maxElem == N-1)
			j = N;
		else
			j = maxElem;

		int i = j-1;
		while(i>1 && A[i-1] > A[0])
			i--;

		vi temp(N);
		// debug(temp);
		int sufLen = N-j;
		for(int k=0; k<sufLen; k++)
			temp[k] = A[j+k];
		// debug(temp);
		int p = 0;
		for(int k=i; k<j; k++) {
			temp[sufLen+p] = A[k];
			p++;
		}
		// debug(temp);
		int p2=0;
		for(int k=sufLen+p; k<N; k++)
			temp[k] = A[p2++];
		// debug(temp);
		reverse(temp.begin()+sufLen, temp.begin()+sufLen+p);
		// debug(temp);

		for(int c:temp)
			cout<<c<<" ";
		cout<<endl;
	}
}
