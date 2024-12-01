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

int path_sum(node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = path_sum(root->left, ans);
    int right = path_sum(root->right, ans);
    int mx = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, mx);
    return max(max(root->data + left, root->data + right), root->data);
}

int maximum_path_sum(node *root)
{
    if (root == NULL)
        return 0;

    int ans = INT32_MIN;
    path_sum(root, ans);
    return ans;
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

    cout << "The Maximum Sum of the path in given binary tree is " << maximum_path_sum(root) << ".";
}