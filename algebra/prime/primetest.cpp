#include<bits/stdc++.h>
using namespace std;


namespace fermat_test {
    long long binpow(long long a, long long b, long long mod) {
        long long wyn = 1;
        while(b) {
            if(b&1) {
                wyn = (wyn*a)%mod;
            }
            a = (a*a)%mod;
            b/=2;
        }
        return wyn;
    }   
    bool test(int p, int it, int seed = 1420) {
        srand (seed);
        if(p <= 4) return p== 3 || p == 2;
        for(int i = 0; i < it; i++) {
            int a = 2 + rand()%(p-3);
            if(binpow(a,p-1,p) != 1) return false;
        }
        return true;
    }
}