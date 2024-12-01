#include <iostream>
#include <stack>
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

void zig_zag_traversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> current_level, next_level;
    bool left_to_right = 1;
    current_level.push(root);

    while (!current_level.empty())
    {
        node *temp = current_level.top();
        current_level.pop();
        cout << temp->data << " ";
        if (left_to_right)
        {
            if (temp->left)
                next_level.push(temp->left);
            if (temp->right)
                next_level.push(temp->right);
        }
        else
        {
            if (temp->right)
                next_level.push(temp->right);
            if (temp->left)
                next_level.push(temp->left);
        }

        if (current_level.empty())
        {
            swap(current_level, next_level);
            left_to_right = !left_to_right;
        }
    }
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

    zig_zag_traversal(root);
}