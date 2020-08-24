using namespace std;
#include<bits/stdc++.h>
int n,p;
const int inc = 2000;
const int maks = 1e6 + 7;
int odp[maks];
int dp[maks];
struct event{
    int l,p,v,typ;
    event(int a, int b, int c, int d = 0) {
        l=a;p=b;v=c,typ = d;
    }
    bool operator() (event a, event b) {
        if(a.l != b.l) return a.l < b.l;
        return a.typ < b.typ;
    }
};
vector<event> tajm;
vector<int> temp;
int renum(int x) {
    return lower_bound(temp.begin(),temp.end(),x) - temp.begin();
}
void wczytaj() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a,b,c; cin >> a >> b >> c;
        tajm.push_back(event(a,b,c,0));
        temp.push_back(a);
        temp.push_back(b);
    }
    cin >> p;
    for(int i = 1; i <= n; i++) {
        int a,b,c; cin >> a >> b >> c;
        tajm.push_back(event(a,a+c,b,i));
        temp.push_back(a);
        temp.push_back(a+c);
    }
    sort(temp.begin(),temp.end());
    for(auto x : tajm) {
        x.l = renum(x.l);x.p = renum(x.p);
    }
}
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    wczytaj();
    for(int i = 1; i <= 1e5 + 5 ; i++)
        dp[i] = 1e5+5;
    for(auto x: tajm) {
        if(x.typ == 0) {
            for(int i = 1e5+5; i >= 0; i--) {
                dp[i+x.v] = min(dp[i+x.v],max(dp[i],x.p));
            }
        }
        else {
            if(dp[x.v] <= x.p)
                odp[x.typ] = true;
        }
    }
    for(int i = 1; i <= p; i++) {
        if(odp[i]) cout << "TAK\n";
        else cout << "NIE\n";
    }
}