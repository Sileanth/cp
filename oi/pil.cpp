#include<bits/stdc++.h>
using namespace std;
struct minimono {
    deque<pair<int,int>> mono;//first-indeks,2-value
    int default_value = 1e9+7;
    void pop(int l) {
        while(mono.size() && mono.front().first <= l) mono.pop_front();
    }
    void push(int id, int val) {
        while(mono.size() && mono.back().second >= val) mono.pop_back();
        mono.push_back({id,val});
    }
    int min() {
        if(mono.size())return mono.front().second;
        else return default_value;
    }
};
struct maxmono {
    deque<pair<int,int>> mono;//first-indeks,2-value
    int default_value = (1e9+7)*-1;
    void pop(int l) {
        while(mono.size() && mono.front().first <= l) mono.pop_front();
    }
    void push(int id, int val) {
        while(mono.size() && mono.back().second <= val) mono.pop_back();
        mono.push_back({id,val});
    }
    int max() {
        if(mono.size())return mono.front().second;
        else return default_value;
    }
};
int n,tr;
vector<int> t;
void wczytaj() {
    cin >> tr >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        t.push_back(x);
    }
}
int calc() {
    maxmono maxm;
    minimono minm;
    int l = 0;
    int p = 0;
    int odp = 0;
    while(p < n) {
        maxm.push(p,t[p]);
        minm.push(p,t[p]);
      //  cout << "przed p: " << p << " l: " << l << " max: " << maxm.max() << " min: " << minm.min() << " dif: " << abs(maxm.max()-minm.min())  << "\n";
        while(abs(maxm.max()-minm.min()) > tr) {
            maxm.pop(l);
            minm.pop(l);
            l++;
        }
        //cout << "po p: " << p << " l: " << l << " max: " << maxm.max() << " min: " << minm.min()<< " dif: " << abs(maxm.max()-minm.min()) << "\n";
        odp = max(odp,p-l+1);
        p++;
    }
    return odp;
}
int main() {
    wczytaj();
    cout << calc();
    

}