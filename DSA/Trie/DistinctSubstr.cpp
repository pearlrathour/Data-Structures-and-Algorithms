#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* links[26];

        bool contains(char ch){
            if(links[ch-'a']) return 1;
            return 0;
        }
};

class Trie{
    public:
        Node* root;
        int cnt=0;

        Trie(){
            root= new Node();
        }

        void insert(int i, string& s){
            Node* temp= root;
            for(int j=i; j<s.size(); j++){
                if(temp->contains(s[j]))
                    temp= temp->links[s[j]-'a'];
                else{
                    Node* curr= new Node();
                    temp->links[s[j]-'a']= curr;
                    temp=curr;
                    cnt++;
                }
            }
        }
};

int countDistinctSubstrings(string &s){
    //    Write your code here.
    Trie t;
    for (int i = 0; i < s.size(); i++)
            t.insert(i, s);
    return t.cnt+1;
}