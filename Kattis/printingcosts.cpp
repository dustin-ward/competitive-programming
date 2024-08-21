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

string lookup = " !   9        \"   6        #  24        $  29        %  22 &  24        \'   3        (  12        )  12        *  17        +  13 ,   7        -   7        .   4        /  10        0  22        1  19 2  22        3  23        4  21        5  27        6  26        7  16 8  23        9  26        :   8        ;  11        <  10        =  14 >  10        ?  15        @  32        A  24        B  29        C  20 D  26        E  26        F  20        G  25        H  25        I  18 J  18        K  21        L  16        M  28        N  25        O  26 P  23        Q  31        R  28        S  25        T  16        U  23 V  19        W  26        X  18        Y  14        Z  22        [  18 \\  10        ]  18        ^   7        _   8        `   3        a  23 b  25        c  17        d  25        e  23        f  18        g  30 h  21        i  15        j  20        k  21        l  16        m  22 n  18        o  20        p  25        q  25        r  13        s  21 t  17        u  17        v  13        w  19        x  13        y  24 z  19        {  18        |  12        }  18 ~ 9";

int main() {
	istringstream iss(lookup);
	map<char,int> M;
	char c; int v;
	while(iss>>c>>v)
		M[c]=v;

	string inp;
	while(getline(cin,inp)) {
		int ans = 0;
		for(char c:inp)
			ans += M[c];
		cout<<ans<<endl;
	}
}
