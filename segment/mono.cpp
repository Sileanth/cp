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