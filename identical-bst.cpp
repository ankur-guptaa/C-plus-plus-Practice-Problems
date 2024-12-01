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

bool is_identical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        bool cond1 = (root1->data == root2->data);
        bool cond2 = is_identical(root1->left, root2->left);
        bool cond3 = is_identical(root1->right, root2->right);

        if (cond1 && cond2 && cond3)
            return true;
        else
            return false;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    if (is_identical(root, root))
        cout << "The BST's are Identical.";
    else
        cout << "The BST's are not Identical.";
}