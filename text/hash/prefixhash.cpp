#include<bits/stdc++.h>
using namespace std;

struct prehash{
    int n,p,mod;
    vector<int> hasz,odw,pot;
    long long fast_pot(long long a, long long b, long long mod) {
        long long wyn = 1;
        a %= mod;
        while(b) {
            if(b&1) {
                wyn = (wyn*a)%mod;
            }
            a = (a*a)%mod;
            b /= 2;
        }
        return wyn%mod;
    }
    prehash(int pr,int modr, string values) {
        reverse(values.begin(),values.end());
        mod = modr;
        p = pr;
        n = values.size();
        hasz.resize(n+1);odw.resize(n+1);pot.resize(n+1,1);
        for(int i = 2; i<= n; i++) {
            pot[i] = ((long long)pot[i-1]*(long long)p)%(long long)mod;
        }
        odw[n] = fast_pot(pot[n],mod-2,mod);
        for(int i = n-1; i >= 1; i--) {
            odw[i] = ((long long)odw[i+1]*(long long)p)%(long long)mod;
        }
        for(int i = 1; i <= n; i++) {
            int x = values[i-1] - 'a'+1;
            hasz[i] = ((long long)x*(long long)pot[i]+(long long)hasz[i-1])%(long long)mod;
        }
    }
    int ask(int a, int b) {
        int wyn = ((long long)hasz[b]-(long long)hasz[a-1]+(long long)mod)%(long long)mod;
        return ((long long)wyn*(long long)odw[a])%(long long)mod;
    }
};

int main() {
    int p,mod; string s; int q;
    cin >> p >> mod >> q >> s;
    prehash xd(p,mod,s);
    while(q--) {
        int a,b; cin >> a >> b;
        cout << xd.ask(a,b) << "\n";
    }
}