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

void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// void flatting_binary_tree(node *&root)
// {
//     if (root == NULL)
//         return;

//     node *temp = root->right;
//     root->right = root->left;
//     root->left = NULL;

//     flatting_binary_tree(root->right);
//     flatting_binary_tree(temp);

//     node *temp2 = root;
//     while (temp2->right != NULL)
//         temp2 = temp2->right;

//     temp2->right = temp;
// }

void flatting_binary_tree(node *&root)
{
    if (root == NULL)
        return;

    flatting_binary_tree(root->left);
    flatting_binary_tree(root->right);

    node *temp = root->right;
    root->right = root->left;
    root->left = NULL;

    node *temp2 = root;
    while (temp2->right != NULL)
        temp2 = temp2->right;
    temp2->right = temp;
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

    preorder(root);
    cout << endl;
    flatting_binary_tree(root);
    inorder(root);
}