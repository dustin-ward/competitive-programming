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

vi A;
unordered_set<int> segTree[300001];

void build(int root, int left, int right) {
    if(left == right) {
        segTree[root].insert(A[left]);
        return;
    }
    if(left > right) return;

    int mid = (left+right)/2;
    int leftRoot = 2*root+1;
    int rightRoot = 2*root+2;
    build(leftRoot, left, mid);
    build(rightRoot, mid+1, right);
    set_union(segTree[leftRoot].begin(), segTree[leftRoot].end(),
              segTree[rightRoot].begin(), segTree[rightRoot].end(),
              inserter(segTree[root], segTree[root].end()));
}

int query(int root, int left, int right, int i, const unordered_set<int> &s) {
    if(left > right) return 0;
    if(left == right) return s.count(A[left]) >= 1;

    if(includes(s.begin(), s.end(), segTree[root].begin(), segTree[root].end()))
        return right - i + 1;

    int count;
    int mid = (left+right)/2;
    int leftRoot = 2*root+1;
    int rightRoot = 2*root+2;
    if(i <= mid) {
        count = query(leftRoot, left, mid, i, s);
        if(count == mid - i + 1)
            count += query(rightRoot, mid+1, right, mid+1, s);
    }
    else
        count = query(rightRoot, mid+1, right, i, s);
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin>>N;
    A.resize(N);
    for(int &i:A)
        cin>>i;

    build(0, 0, N-1);

    int Q; cin>>Q;
    while(Q--) {
        int I,M; cin>>I>>M;
        unordered_set<int> S;
        while(M--) {
            int temp; cin>>temp;
            S.insert(temp);
        }
        cout<<query(0, 0, N-1, I-1, S)<<endl;
    }
}