#include<bits/stdc++.h>
using namespace std;
//1 wymiarowy union find bez rozmiaru zbiorów
struct uf2d {
    vector<vector<pair<int,int>>> oj;
    vector<vector<int>> sajz;
    uf2d(int n,int m) {
        oj.resize(n+1,vector<pair<int,int> > (m+1));
        sajz.resize(n+1,vector<int> (m+1,1));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= m; j++) {
                oj[i][j] = {i,j};
            }
        }
    }
    pair<int,int> szuk(pair<int,int> x) { 
        return (oj[x.first][x.second] == x) ? x : oj[x.first][x.second] = szuk(oj[x.first][x.second]); 
    }
    pair<int,int> szuk(int x, int y) { 
        return (oj[x][y] == make_pair(x,y)) ? oj[x][y] : oj[x][y] = szuk(oj[x][y]); 
    }
    void loncz(pair<int,int> a, pair<int,int> b) { 
        a = szuk(a); b= szuk(b);
        oj[b.first][b.second] = a; 
        sajz[a.first][a.second] += sajz[b.first][b.second];
    }
    
};

int main() {
    
}