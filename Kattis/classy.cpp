#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

#define INF 1000000000
#define sz(x) (int)(x).size()
#define debug(a) cerr << #a << " = " << (a) << endl;

template<typename T, typename U> ostream& operator<<(ostream& o, const pair<T, U>& x) { o << "(" << x.first << ", " << x.second << ")"; return o; }
template<typename T> ostream& operator<<(ostream& o, const vector<T>& x) { o << "["; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "]"; return o; }
template<typename T> ostream& operator<<(ostream& o, const set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_set<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T> ostream& operator<<(ostream& o, const unordered_multiset<T>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_map<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }
template<typename T, typename U> ostream& operator<<(ostream& o, const unordered_multimap<T, U>& x) { o << "{"; int b = 0; for (auto& a : x) o << (b++ ? ", " : "") << a; o << "}"; return o; }

struct Person {
    string name;
    vector<string> _class;
};

map<string,int> M = {
    {"lower", 0},
    {"middle", 1},
    {"upper", 2}
};

bool f(const Person &a, const Person &b) {
    for(int i=0; i<10; ++i) {
        if(M[a._class[i]] > M[b._class[i]])
            return true;
        if(M[a._class[i]] < M[b._class[i]])
            return false;
    }
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin>>T;
    while(T--) {
        int N; cin>>N;
        vector<Person> people;
        for(int i=0; i<N; ++i) {
            Person p;
            string _class, g;
            cin>>p.name>>_class>>g;
            p.name.pop_back();

            replace(_class.begin(), _class.end(), '-', ' ');
            istringstream iss(_class);
            while(iss>>g)
                p._class.push_back(g);
            reverse(p._class.begin(), p._class.end());

            while(p._class.size() < 10)
                p._class.push_back("middle");

            people.push_back(p);
        }

        sort(people.begin(), people.end(), f);
        for(auto &p:people)
            cout<<p.name<<endl;
        cout<<"=============================="<<endl;
    }
}