#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node *buildTree(vector<int> v)
{
    if (v.size() == 0 || v[0] == -1)
        return nullptr;
    Node *root = new Node(v[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < v.size())
    {
        Node *t = q.front();
        q.pop();
        if (i < v.size() && v[i] != -1)
        {
            t->left = new Node(v[i]);
            q.push(t->left);
        }
        i++;
        if (i < v.size() && v[i] != -1)
        {
            t->right = new Node(v[i]);
            q.push(t->right);
        }
        i++;
    }
    return root;
}
void pre(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}
int main()
{
    cout<<"Enter the array string:";
    string s;
    getline(cin, s);
    vector<int> v;
    stringstream ss(s);
    int num;
    while (ss >> num)
    {
        v.push_back(num);
    }
    Node *root = buildTree(v);
    pre(root);
}