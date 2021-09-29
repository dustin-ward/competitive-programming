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

ll merge(vector<int> &arr, vector<int> &cpy, int l, int m, int r) {
    ll count = 0;
    int i=l, j=m, k=l;
    while((i <= m - 1) && (j <= r)) {
        if(arr[i] <= arr[j])
            cpy[k++] = arr[i++];
        else {
            cpy[k++] = arr[j++];
            count += m-i;
        }
    }
    while (i <= m - 1)
        cpy[k++] = arr[i++];
 
    while (j <= r)
        cpy[k++] = arr[j++];
 
    for (i=l; i <= r; i++)
        arr[i] = cpy[i];

    return count;
}

ll merge_sort(vector<int> &arr, vector<int> &cpy, int l, int r) {
    if(r > l) {
        int m = (r+l)/2;
        return merge_sort(arr, cpy, l, m) + merge_sort(arr, cpy, m+1, r) + merge(arr, cpy, l, m+1, r);
    }
    return 0;    
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin>>N;
    vector<int> v(N), temp(N);
    for(int i=0; i<N; i++) {
        cin>>v[i];
    }

    cout<<merge_sort(v, temp, 0, N-1)<<endl;;
}