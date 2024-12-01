#include <iostream>
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

void nodes_in_subtree(node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    nodes_in_subtree(root->left, k - 1);
    nodes_in_subtree(root->right, k - 1);
}

int nodes_in_ancestor(node *root, node *target, int k)
{
    if (root == NULL || k < 0)
        return -1;
    if (root == target)
    {
        nodes_in_subtree(root, k);
        return 1;
    }

    int dl = nodes_in_ancestor(root->left, target, k);
    if (dl != -1)
    {
        if (dl == k)
            cout << root->data << " ";
        else
            nodes_in_subtree(root->right, k - dl - 1);
        return dl + 1;
    }
    int dr = nodes_in_ancestor(root->right, target, k);
    if (dr != -1)
    {
        if (dr == k)
            cout << root->data << " ";
        else
            nodes_in_subtree(root->left, k - dr - 1);
        return dr + 1;
    }
    return -1;
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

    nodes_in_ancestor(root, root->left, 2);
}