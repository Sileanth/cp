#include<bits/stdc++.h>
using namespace std;
namespace sieve {
vector<int> prime;
vector<bool> p;

void sieve(int n) {
    p.resize(n+1,0);
    p[0] = true;p[1] = true;
    for(int i = 2; i <= n; i++) {
        if(!p[i]) {
            prime.push_back(i);
            for(int j = i*i; j<= n; j *= i) {
                p[j] = true;
            }
        }
    }
}

}

namespace linearsieve {
vector<int> prime;
vector<int> p;

void linearsieve(int n) {
    p.resize(n+1,0);
    
    for(int i = 2; i <= n; i++) {
        if(!p[i]) {
            prime.push_back(i);
            p[i] = i;
        }
        for(int j = 0; j < prime.size() && prime[j]*i <= n && p[j] <= p[i]; j++) {
            p[i*prime[j]] = prime[j];
        }
    }
}

}

