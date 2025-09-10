
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
Node *insert(Node *root, int k)
{
    if (!root)
        return new Node(k);
    if (root->data > k)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);

    return root;
}
Node *build(vector<int> v)
{

    Node *root = nullptr;
    for (int it : v)
    {
        root = insert(root, it);
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    cout << "Enter the bst array:";
    string s;
    getline(cin, s);
    stringstream ss(s);
    int num;
    vector<int> v;
    while (ss >> num)
    {
        v.push_back(num);
    }
    Node *root = build(v);
    inorder(root);
}