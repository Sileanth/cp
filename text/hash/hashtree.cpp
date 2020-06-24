#include<bits/stdc++.h>
using namespace std;


struct hashtree {
    long long p;
    long long mod;
    long long n;
    vector<long long> pot;
    vector<long long> t;
    hashtree(long long base, long long m, long long k, string val) {
        p = base;
        mod = m;
        n = 1<<(k);
        pot.resize(k+1);
        pot[0] = 1;
        for (long long i = 1; i < pot.size(); ++i)
            pot[i] = (pot[i-1]*p)%mod;
        reverse(pot.begin(),pot.end());
        t.resize(n<<1);
        for(long long i = 0; i < val.size(); i++) {
            t[n+i] = val[i]-'a'+1;
        }
        for(long long i = n-1; i > 0; --i) {
            t[i] = (t[i<<1]*pot[log2(i)] + t[(i<<1)+1])%mod; 
        }
    }
    void update(long long i, long long val) {
        i += n;
        t[i] = val;
        
        for(i>>=1; i>= 1; i >>= 1) {
            t[i] = (t[i<<1]*pot[log2(i)] + t[(i<<1)+1])%mod;
        }
    }
    long long query(long long l, long long p) {
        l+=n;p+=n;
        if(l==p)return t[l];
        long long left_score = t[l];
        long long right_score = t[p];
        while(l/2 != p/2) {
            if(!(l^1)) {
                left_score = (left_score + t[l+1]*pot[log2(l>>1)])%mod;
            }
            if(p^1) {
                right_score = (t[p-1] + right_score*pot[log2(p>>1)])%mod;
            }
            p >>= 1;
            l >>= 1;
        }
        return (left_score+right_score*pot[log2(p>>1)])%mod;
    }
};
int main() {
    long long p = 31, mod = 1e9+7, k = 3; string s = "abcdef";
    hashtree xd(p,mod,k,s);
    for(long long i = 0; i < xd.t.size(); i++) {
        cout << "nr: " << i << " val: " << xd.t[i] << " pot: " << xd.pot[log2(i)] << "\n";
    }
    long long q= 10;
   while(q--) {
        long long a,b; cin >> a >> b;
        cout << xd.query(a,b);
    }
}