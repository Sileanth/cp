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
    void loncz(int x, int y) { 
        x = szuk(x); y = szuk(y);
        sajz[x] += sajz[y];
        oj[x] = y;
    }
};

int main() {
    
}