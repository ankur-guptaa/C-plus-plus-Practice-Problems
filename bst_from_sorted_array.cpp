#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *bst_from_sorted_array(int arr[], int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = bst_from_sorted_array(arr, start, mid - 1);
    root->right = bst_from_sorted_array(arr, mid + 1, end);

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n = 7;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7};

    node *root = bst_from_sorted_array(arr, 0, n - 1);
    inorder(root);
}