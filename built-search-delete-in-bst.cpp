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

node *built_binary_search_tree(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (root->data > val)
        root->left = built_binary_search_tree(root->left, val);
    else
        root->right = built_binary_search_tree(root->right, val);

    return root;
}

bool search_in_bst(node *root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    else if (root->data > key)
        return search_in_bst(root->left, key);
    else
        return search_in_bst(root->right, key);
}

node *inorder_successor(node *root)
{
    if (root != NULL)
        root = root->right;
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

node *delete_in_bst(node *root, int key)
{
    if (root == NULL)
        return root;

    if (root->data > key)
        root->left = delete_in_bst(root->left, key);
    else if (root->data < key)
        root->right = delete_in_bst(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = inorder_successor(root);
            root->data = temp->data;
            root->right = delete_in_bst(root->right, temp->data);
        }
    }
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
    int n = 14;
    int arr[n] = {7,4,2,6,12,9,16,1,3,5,17,15,10,8};

    node *root = NULL;
    for (int i = 0; i < n; i++)
        root = built_binary_search_tree(root, arr[i]);

    inorder(root);

    if (search_in_bst(root, 9))
        cout << "\nKey exists.\n";
    else
        cout << "\nKey doesnot exists.\n";

    inorder(root);
    delete_in_bst(root, 12);
    cout << endl;
    inorder(root);
}