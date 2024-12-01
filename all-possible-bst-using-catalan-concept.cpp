#include <iostream>
#include <vector>
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

vector<node *> construct_bst(int start, int end)
{
    vector<node *> roots;

    if (start > end)
    {
        roots.push_back(NULL);
        return roots;
    }

    for (int i = start; i <= end; i++)
    {
        vector<node *> left_subtree = construct_bst(start, i - 1);
        vector<node *> right_subtree = construct_bst(i + 1, end);

        for (int j = 0; j < left_subtree.size(); j++)
        {
            for (int k = 0; k < right_subtree.size(); k++)
            {
                node *temp = new node(i);
                temp->left = left_subtree[j];
                temp->right = right_subtree[k];
                roots.push_back(temp);
            }
        }
    }
    return roots;
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int a = 1, b = 3;
    vector<node *> roots = construct_bst(a, b);

    for (int i = 0; i < roots.size(); i++)
    {
        cout << i + 1 << " : ";
        preorder(roots[i]);
        cout << endl;
    }
}