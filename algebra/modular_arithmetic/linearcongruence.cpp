using namespace std;
#include <bits/stdc++.h>

namespace linearcongruation {
    int egcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1,y1;
    int nwd = egcd(b,a%b,x1,y1);
    x = y1;
    y = x1-y1*(a/b);
    return nwd;
}

    bool dioph(int a, int b, int c, int &x, int &y) {
        int nww = egcd(abs(a),abs(b),x,y);
        if(c%nww)return false;
        x = x*c/nww;
        y = y*c/nww;
        if(a<0)x*=-1;
        if(b<0)y*=-1;
        return true;
    }
    bool linear_congruence(int a, int b, int n, int &x) {
        int y;
        return dioph(a,n,b,x,y);
    }
}