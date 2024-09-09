#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* links[26];
        bool fl=0; 
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
    
    void insert(string word) {
        Node* temp= root;
        for(char ch : word){
            if(temp->contains(ch))
                temp= temp->links[ch-'a'];
            else {
                  Node *curr = new Node();
                  temp->links[ch - 'a'] = curr;
                  temp = curr;
                }
            }
        
        temp->fl=1;
    }

    bool prefExits(string& word){
        Node* temp= root;
        for(char ch : word){
            if(temp->contains(ch)){
                temp= temp->links[ch-'a'];
                if(temp->fl==0) return 0;
            }
            else return 0;
        }
        return temp->fl;
    }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie t;
    for(auto &it : a) t.insert(it);
    int mx=0;
    string longest="";
    for(string it : a){
        if(t.prefExits(it)){
            if (it.size() > longest.size()) {
                mx = it.size();
                longest = it;
            } 
            else if (it.size()==longest.size() && it<longest)
                longest=it;
        }
    }
    if(mx==0) return "None";
    return longest;
}