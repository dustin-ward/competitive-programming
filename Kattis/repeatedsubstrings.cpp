#include <bits/stdc++.h>
#define sz(S) (int)S.size()
#define debug(a) cerr << #a << " = " << a << endl;
#define vi vector<int>
#define all(S) begin(S),end(S)
using namespace std;

struct SuffixArray {
    vi sa, lcp;
    SuffixArray(string &s, int lim=256) {
        int n = sz(s) + 1, k=0, a, b;
        vi x(all(s)+1), y(n), ws(max(n,lim)), rank(n);
        sa = lcp = y, iota(all(sa), 0);
        for(int j=0, p=0; p<n; j=max(1,j*2), lim=p) {
            p=j, iota(all(y), n-j);
            for(int i=0; i<n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            for(int i=0; i<n; i++) ws[x[i]]++;
            for(int i=1; i<lim; i++) ws[i] += ws[i-1];
            for(int i=n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x,y), p=1, x[sa[0]] = 0;
            for(int i=1; i<n; i++) a=sa[i-1], b=sa[i], x[b] = 
                (y[a] == y[b] && y[a+j] == y[b+j]) ? p-1 : p++;
        }
        for(int i=1; i<n; i++) rank[sa[i]] = i;
        for(int i=0, j; i<n-1; lcp[rank[i++]] = k)
            for(k && k--, j=sa[rank[i] - 1]; s[i+k] == s[j+k]; k++);
    }
};

int main() {
    string s; cin>>s;
    SuffixArray sa(s);

//    for(int i:sa.sa)
//        cout<<i<<" ";
//    cout<<endl;

//    for(int i:sa.lcp)
//        cout<<i<<" ";
//    cout<<endl;

    int ans = 0;
    int ansIdx;
    for(int i=sz(s); i>=0; i--) {
        if(sa.lcp[i] >= ans) {
            ans = sa.lcp[i];
            ansIdx = i;
        }
    }

    cout<<s.substr(sa.sa[ansIdx], ans)<<endl;
}
