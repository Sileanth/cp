#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define f first
#define s second
int n,m,k,licz;
const int maks = 3e5 + 7;
vector<int> bazy[maks];
pair<int,int> bs[maks];
vector<int> check[maks];
int wym[maks];
int odp[maks];
struct deszcz{
    int l,p,v;
    deszcz(int lq, int pq, int vq) {
        l = lq; p = pq; v = vq;
    }
};
vector<deszcz> deszcze;
ll t[maks*2 + 5];
void modify(int l, int r, ll value) {
    r++;
  for (l += maks, r += maks; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}
ll query(int p) {
  ll res = 0;
  for (p += maks; p > 0; p >>= 1) res += t[p];
  return res;
}
void wczytaj() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        bazy[x].pb(i);
    }
    for(int i = 1; i<= n; i++) {
        cin >> wym[i];
    }
    cin >> k;
    deszcze.pb(deszcz(0,0,0));
    for(int i = 0; i < k; i++) {
        int l,p,v; cin >> l >> p >> v;
        deszcze.pb(deszcz(l,p,v));
    }
  
}
void binsearch() {
    for(int i = 1; i <= n; i++) {
        bs[i] = {0,k+1};
    }
    int x= 0;
    while(x < log2(k) + 20) {
        x++;
        for(int i = 1; i <= n; i++) {
            int m = (bs[i].f+bs[i].s)/2;
            check[m].pb(i);
        }
        for(int i = 0; i < maks*2 + 5; i++)
            t[i] = 0;
        for(int i = 1; i <= k; i++) {
            if(deszcze[i].l <= deszcze[i].p) {
                modify(deszcze[i].l,deszcze[i].p,deszcze[i].v);
            }
            else {
                modify(deszcze[i].l,m,deszcze[i].v);
                modify(1,deszcze[i].p,deszcze[i].v);
            }
            for(int pan : check[i]) {
                ll sum = 0;
                for(int baza : bazy[pan]) {
                    sum += (ll)query(baza);
                    if(sum >= wym[pan])break;
                }
              // cout << "pan: " << pan << " sum: " << sum << " m: " << i; 
                if(sum >= wym[pan]) {
                    bs[pan].s = i;
                    odp[pan] = i;
                }
                else {
                    bs[pan].f = i;
                }
               // cout << " l: " << bs[pan].f << " p: " << bs[pan].s << "\n";
            }
            check[i].clear();
        }
    }

}
int main() {
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    wczytaj();
    binsearch();
    for(int i = 1; i <= n; i++) {
        if(odp[i]) cout << odp[i] << "\n";
        else cout << "NIE\n";
    }
}