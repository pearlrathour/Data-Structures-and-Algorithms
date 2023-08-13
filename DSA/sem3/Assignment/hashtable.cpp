#include <bits/stdc++.h>
using namespace std;

struct Hash{
    int bucket;
    // Pointer to an array containing buckets
    list<int> *table;

    Hash(int b){
    this->bucket = b;
    table = new list<int>[bucket];
    }

    void insertItem(int x);
    int hashFunction(int x){
        return ((2*x +5) % bucket);
    }
    void displayHash();
};


void Hash::insertItem(int key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::displayHash(){
    for (int i = 0; i < bucket; i++){
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}


int main(){
    int a[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(n);
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);
    h.displayHash();
    return 0;
}