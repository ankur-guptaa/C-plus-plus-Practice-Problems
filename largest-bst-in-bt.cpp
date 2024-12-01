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

struct info
{
    int min;
    int max;
    int size;
    int ans;
    bool is_bst;
};

info largest_bst(node *root)
{
    if (root == NULL)
        return {INT32_MAX, INT32_MIN, 0, 0, true};
    else if (root->left == NULL && root->right == NULL)
        return {root->data, root->data, 1, 1, true};

    info curr;
    info left_subtree = largest_bst(root->left);
    info right_subtree = largest_bst(root->right);

    curr.min = min(root->data, min(left_subtree.min, right_subtree.min));
    curr.max = max(root->data, max(left_subtree.max, right_subtree.max));
    curr.size = 1 + left_subtree.size + right_subtree.size;
    if (root->data > left_subtree.max && root->data < right_subtree.min && left_subtree.is_bst && right_subtree.is_bst)
    {
        curr.ans = curr.size;
        curr.is_bst = true;
    }
    else
    {
        curr.ans = max(left_subtree.ans, right_subtree.ans);
        curr.is_bst = false;
    }
    return curr;
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

    info res = largest_bst(root);
    cout << "The Largest BST in given BT is of size " << res.ans << ".";
}