#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    // Constructor
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *Insert(Node *root)
{
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

void markparent(Node *root, unordered_map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    vector<int> res;
    if (!root)
        return res;

    unordered_map<Node *, Node *> parent_track; // node->parent
    markparent(root, parent_track);
    unordered_map<Node *, bool> vis;

    queue<Node *> q;
    q.push(target);
    vis[target] = 1;
    int level = 0;

    while (!q.empty())
    {
        if (level++ == k)
            break;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left && !vis[curr->left])
            {
                q.push(curr->left);
                vis[curr->left] = 1;
            }
            if (curr->right && !vis[curr->right])
            {
                q.push(curr->right);
                vis[curr->right] = 1;
            }
            if (parent_track[curr] && !vis[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                vis[parent_track[curr]] = 1;
            }
        }
    }

    while (!q.empty())
    {
        res.push_back(q.front()->key);
        q.pop();
    }
    return res;
}

int main()
{
    Node *root = NULL;
    int maxsum = INT_MIN;
    root = Insert(root);
    distanceK(root, target, 4);
    
    return 0;
}