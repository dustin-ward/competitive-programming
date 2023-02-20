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

using u32    = uint_least32_t; 
using engine = std::mt19937;

int main() {
	double tic = time();
	int N,S,D,C; cin>>N>>S>>D>>C;
	vector<vi> G(N);
	for(int i=0; i<C; ++i) {
		string s; cin>>s;
		istringstream iss(s);
		int u; iss>>u;
		int v;
		while(iss>>v)
			G[u-1].push_back(v-1);
	}
//	for(int i=0; i<N; ++i) {
//		if(!sz(G[i]))
//			G[i].push_back((i+1)%N);
//	}
	int range = S*D;

	random_device os_seed;
  	const u32 seed = os_seed();

  	engine generator( seed );
  	uniform_int_distribution< u32 > distribute(0, 1000);
	//std::cout << distribute( generator ) << std::endl;

	vector<ll> V(N,0);
	double total = 0;
	int curHouse=0;
	while(time()-tic < 0.8) {
		total++;
		V[curHouse]++;
		if(G[curHouse].empty()) {
			curHouse = (curHouse + ((distribute(generator)+S)%range)) % N;
		}
		else {
			curHouse = G[curHouse][distribute(generator)%sz(G[curHouse])];
		}
	}
	debug(V);
	vector<pair<int,double>> ans(N);
	for(int i=0; i<N; ++i)
		ans[i] = {i+1, V[i]/total};
	sort(all(ans), [](const pair<int,double> &a, const pair<int,double> &b) {
					if(a.snd == b.snd)
						return a.fst < b.fst;
					return a.snd > b.snd;
				}
	);

	for(int i=0; i<3; ++i)
		cout<<fixed<<setprecision(3)<<ans[i].fst<<" "<<ans[i].snd<<endl;

	debug(time());
}
