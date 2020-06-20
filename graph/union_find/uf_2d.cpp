#include<bits/stdc++.h>
using namespace std;
//1 wymiarowy union find bez rozmiaru zbiorów
struct uf1d {
    int n,m;
    vector<int> oj;
    uf1d(int sn, sm) {
        n = sn; m = sm
        oj.resize(sajz);
        for(int i = 1; i <= sajz; i++) {
            oj[i] = i;
        }
    }
    int szuk(int u) { 
        return (oj[u] == u) ? oj[u] : oj[u] = szuk(oj[u]); 
    }
    void loncz(int x, int y) { 
        oj[szuk(x)] = szuk(y); 
    }
};

int main() {
    
}