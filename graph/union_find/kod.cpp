#include<bits/stdc++.h>
using namespace std;

struct uf1d {
    int n;
    vector<int> oj;
    uf1d(int sajz) {
        for(int i = 0; i <= n; i++) {
            oj.push_back(i);
        }
    }
    int szuk(int u) { return (oj[u] == u) ? oj[u] : oj[u] = szuk(oj[u]); }
    void loncz(int x, int y) { oj[lonczc(x)] = loncz(y); }
};

int main() {
    cout << "xd";
}