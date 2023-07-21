#include <bits/stdc++.h>
using namespace std;

class LRUCache{
public:
    class Node{
    public:
        int key;
        int val;
        Node *prev, *next;

        Node(int k, int v){
            key = k;
            val = v;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node *> LRU;

    LRUCache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add(Node *node){
        Node *temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node *node){
        Node *pre = node->prev;
        Node *nex = node->next;

        pre->next = nex;
        nex->prev = pre;
    }

    int get(int key){
        if (LRU.find(key) != LRU.end()){
            Node *res = LRU[key];
            int ans = res->val;

            LRU.erase(key);
            deleteNode(res);
            add(res);

            LRU[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value){
        if (LRU.find(key) != LRU.end()){
            Node *curr = LRU[key];
            LRU.erase(key);
            deleteNode(curr);
        }

        if (LRU.size() == cap){
            LRU.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        add(new Node(key, value));
        LRU[key] = head->next;
    }
};