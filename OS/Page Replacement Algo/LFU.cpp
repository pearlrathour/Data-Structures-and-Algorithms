#include <bits/stdc++.h>
using namespace std;

map<int, int> freq, cache;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int capacity, p;

void put(int key, int value){
    if (cache.size() == capacity){
        int lfu = pq.top().first;
        pq.pop();
        cache.erase(lfu);
        freq.erase(lfu);
    }
    cache[key] = value;
    freq[key] = 1;
    pq.push({1, key});
}

int get(int key){
    if (cache.find(key) != cache.end()){
        int f = freq[key];
        freq.erase(key);
        pq.push({f + 1, key});
        freq[key] = f + 1;
        return cache[key];
    }
    return -1;
}

int main(){
    p, capacity;
    cin >> p >> capacity;
    vector<int> pages(p);
    for (int i = 0; i < p; i++){
        cin >> pages[i];
        put(pages[i],i);
        cout<<get(pages[i])<<endl;
    }
    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
    return 0;
}