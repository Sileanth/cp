#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
// x*a+b*y = gcd(a,b) find gcd,x,y
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

//a*x+b*y=c  find x,y if exist
bool dioph(int a, int b, int c, int &x, int &y) {
    int nww = egcd(abs(a),abs(b),x,y);
    if(c%nww)return false;
    x = x*c/nww;
    y = y*c/nww;
    if(a<0)x*=-1;
    if(b<0)y*=-1;
    return true;
}


