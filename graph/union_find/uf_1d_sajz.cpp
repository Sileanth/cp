#include<bits/stdc++.h>
using namespace std;
//1 wymiarowy union find z rozmiarem zbiorów
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
    void loncz(int x, int y) { //dołącza spójną y do spójnej x 
        x = szuk(x); y = szuk(y);
        sajz[x] += sajz[y];
        oj[y] = x;
    }
};

int main() {
    int n,q; cin >> n >> q;
    uf1ds uf(n);
    while(q--) {
        int typ; cin >> typ;
        if(typ) {
            int a, b; cin >> a >> b;
            uf.loncz(a,b);
        }
        else {
            int a; cin >> a;
            cout <<"ojciec " << uf.szuk(a) << " rozmiar" << uf.sajz[uf.szuk(a)] << "\n";
        }
    }
}