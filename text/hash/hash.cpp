#include<bits/stdc++.h>
using namespace std;


int hasz(string s, long long p, long long mod) {
    long long wyn = 0;
    for(char z: s) {
        long long x = z -'a';
        wyn *= p;
        wyn += x;
        wyn %= mod;
    }
    return wyn;
}

int main() {
    int q; cin >> q;
    while(q--) {
        string s; int a,b;
        cin >> s >> a >> b;
        cout << hasz(s,a,b) << "\n";    
    }
}