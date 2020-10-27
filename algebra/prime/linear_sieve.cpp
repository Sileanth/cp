#include<bits/stdc++.h>
using namespace std;
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
