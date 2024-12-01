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

    node()
    {
        left = NULL;
        right = NULL;
    }
};

node *bst_from_preorder(int preorder[], int *preorder_idx, int key, int min, int max, int n)
{
    if (*preorder_idx >= n)
        return NULL;

    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preorder_idx = *preorder_idx + 1;
        if (*preorder_idx < n)
            root->left = bst_from_preorder(preorder, preorder_idx, preorder[*preorder_idx], min, key, n);
        if (*preorder_idx < n)
            root->right = bst_from_preorder(preorder, preorder_idx, preorder[*preorder_idx], key, max, n);
    }
    return root;
}

void print_preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main()
{
    int n = 5;
    int preorder[n] = {10, 2, 1, 13, 11}, preorder_idx = 0;

    node *root = bst_from_preorder(preorder, &preorder_idx, preorder[preorder_idx], INT32_MIN, INT32_MAX, n);
    print_preorder(root);
}