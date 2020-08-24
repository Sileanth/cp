using namespace std;
#include <bits/stdc++.h>

struct uf1ds {
    vector<int> oj;
    vector<int> sajz;
    uf1ds(int n) {
        oj.resize(n+1);
        sajz.resize(n+1,1);
        for(int i = 1; i <= n; i++) {
            oj[i] = i;
        }
    }
    int szuk(int u) { 
        return (oj[u] == u) ? oj[u] : oj[u] = szuk(oj[u]); 
    }
    int rozm(int x) {
        x = szuk(x);
        return sajz[x];
    }
    void loncz(int x, int y) { //dołącza spójną y do spójnej x 
        x = szuk(x); y = szuk(y);
        sajz[x] += sajz[y];
        oj[y] = x;
    }
};

int main() {
    int n,m; cin >> n >> m;
    uf1ds uf(n);
    int maks = 0;
    int x= 0;
    while(m--) {
        int a,b; cin >> a >> b;
        uf.loncz(a,b);
        if(uf.sajz[uf.szuk(a)] > maks) {
            maks = uf.sajz[uf.szuk(a)];
            x = uf.szuk(a);
        }
    }
    int licz = n/3;
    for(int i = 1; i <= n; i++) {
        if(uf.szuk(i) == x) {
            cout << i << " ";
            licz--;
        }
    }
    
}