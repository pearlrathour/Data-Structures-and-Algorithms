#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* links[26];
        bool end=0;
        bool start=0; 
        bool contains(char ch){
            return links[ch-'a']!=NULL; 
        }   
};

class Trie {
public:
    Node* root;

    Trie() {
        root= new Node();
    }
    
    //O(N)
    void insert(string word) {
        Node* temp= root;
        for(char ch : word){
            if(temp->contains(ch))
                temp= temp->links[ch-'a'];
            else{
                Node* curr= new Node();
                temp->links[ch-'a']= curr;
                temp=curr;
                temp->start=1;
            }
        }
        temp->end=1;
    }
    
    //O(N)
    bool search(string word) {
        Node* temp= root;
        for(char ch : word){
            if(temp->contains(ch))
                temp= temp->links[ch-'a'];
            else return 0;
        }
        return temp->end;
    }
    
    //O(N)
    bool startsWith(string prefix) {
        Node* temp= root;
        for(char ch : prefix){
            if(temp->contains(ch))
                temp= temp->links[ch-'a'];
            else return 0;
        }
        return temp->start;
    }
};