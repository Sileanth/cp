using namespace std;
#include<bits/stdc++.h>
int n,m;
const int maks = 3005;
bool exi[maks]; 
bool t[maks][maks];

void wczytaj() {
    cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        t[a][b] = true;
        t[b][a] = true;
    }
    for(int i = 1; i <= n; i++) {
        exi[i] = true;
    }
}
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    wczytaj();
    for(int i = 1; i <= n; i++) {
        if(exi[i]) {
            for(int j = 1; j<= n; j++) {
                if(exi[j] && !t[i][j] && i != j) {
                    exi[j] = false;
                    exi[i] = false;
                    break;
                }
            }
        }
    }
    int licz = n/3;
    for(int i = 1; i <= n && licz; i++) {
        if(exi[i]) {
            cout << i << " ";
            licz--;
        }
    }
    
}