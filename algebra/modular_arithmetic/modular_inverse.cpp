using namespace std;
#include <bits/stdc++.h>

namespace modular_inverse {

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
    int modular_inverse(int a, int mod) {
        return binpow(a,mod-2,mod);
    }
}