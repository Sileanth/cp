#include<bits/stdc++.h>
using namespace std;
const int maks = 1e8;
vector<int> prime;
bool p[maks];

void sieve(int n) {
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
