#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    // Constructor
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *Insert(Node *root){
    cout << "Enter value to be entered : ";
    int val;
    cin >> val;
    root = new Node(val);

    if (val == -1)
        return NULL;

    cout << "Enter value to left of " << val << " : ";
    root->left = Insert(root->left);
    cout << "Enter value to right of " << val << " : ";
    root->right = Insert(root->right);

    return root;
}

int width(Node *root){
    int w = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty()){
        int index = q.front().second;
        int l = q.size();
        int first, last;

        for (int i = 0; i < l; i++){
            long int curr_index = q.front().second - index;
            Node *node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_index;
            if (i == l - 1)
                last = curr_index;

            if (node->left)
                q.push({node->left, curr_index * 2 + 1});
            if (node->right)
                q.push({node->right, curr_index * 2 + 2});
        }
        w = max(w, last - first + 1);
    }
    return w;
}

int main()
{
    Node *root = NULL;
    root = Insert(root);

    cout<< width(root);
    return 0;
}