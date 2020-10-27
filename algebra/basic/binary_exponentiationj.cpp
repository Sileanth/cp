#include <bits/stdc++.h>
using namespace std;
//a^b % mod
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
// (a^(b^c))%mod
long long binpowpow(long long a, long long b, long long c, long long mod) {
    return binpow(a,binpow(b,c,mod-1),mod);
    
}
//(a*b)%mod
long long binmult(long long a, long long b, long long mod) {
    if(b == (long long)0)return 0;
    if(b == (long long)1)return a;
    if(b%2)return (binmult(a, b/(long long)2, mod)*(long long)2+a)%mod;
    return  (binmult(a,b/(long long)2,mod)*(long long)2)%mod;
}

