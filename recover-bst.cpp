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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculate(node *root, node **first, node **mid, node **last, node **pre)
{
    if (root == NULL)
        return;

    calculate(root->left, first, mid, last, pre);
    if (*pre)
    {
        if (root->data < (*pre)->data && !*first)
        {
            *first = *pre;
            *mid = root;
        }
        else if (root->data < (*pre)->data && *first)
            *last = root;
    }
    *pre = root;
    calculate(root->right, first, mid, last, pre);
}

void recover_bst(node *root)
{
    if (root == NULL)
        return;

    node *pre = NULL, *first = NULL, *mid = NULL, *last = NULL;
    calculate(root, &first, &mid, &last, &pre);

    if (first && last)
        swap(&first->data, &last->data);
    else if (first && mid)
        swap(&first->data, &mid->data);
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
    node *root = new node(5);
    root->left = new node(7);
    root->right = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    inorder(root);
    cout << endl;
    recover_bst(root);
    inorder(root);
}