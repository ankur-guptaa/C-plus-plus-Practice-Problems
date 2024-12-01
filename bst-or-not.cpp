#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool is_bst(node *root, int min, int max)
{
    if (root == NULL)
        return true;

    if ((root->data > min && root->data < max) && is_bst(root->left, min, root->data) && is_bst(root->right, root->data, max))
        return true;

    return false;
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    if (is_bst(root, INT32_MIN, INT32_MAX))
        cout << "It's a BST.";
    else
        cout << "It's not a BST.";
}