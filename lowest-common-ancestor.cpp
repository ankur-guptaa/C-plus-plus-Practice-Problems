#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    node()
    {
        left = NULL;
        right = NULL;
    }
};

bool get_path(node *root, int n, vector<int> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root->data);
    if (root->data == n)
        return true;

    if (get_path(root->left, n, path) || get_path(root->right, n, path))
        return true;

    path.pop_back();
    return false;
}

int lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return -1;

    vector<int> path1, path2;

    if (!get_path(root, n1, path1) || !get_path(root, n2, path2))
        return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if (path1[i] != path2[i])
            break;
    }
    return path1[i - 1];
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right->left->left = new node(12);
    root->right->left->right = new node(13);
    root->right->right->left = new node(14);
    root->right->right->right = new node(15);

    int LCA = lca(root, 12, 15);
    cout << "The Lowest Common Ancestor is " << LCA << ".";
}