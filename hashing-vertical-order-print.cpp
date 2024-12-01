#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

struct node
{
    int data;
    node *left, *right;

    node()
    {
        left = right = NULL;
    }

    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *make_binary_tree(vi &arr, int n, int i)
{
    if (i >= n)
        return NULL;

    node *root = new node(arr[i]);
    root->left = make_binary_tree(arr, n, (2 * i) + 1);
    root->right = make_binary_tree(arr, n, (2 * i) + 2);
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void vertical_order(node *root, map<int, vi> &mp, int distance)
{
    if (root == NULL)
        return;
    mp[distance].push_back(root->data);
    vertical_order(root->left, mp, distance - 1);
    vertical_order(root->right, mp, distance + 1);
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];
    node *root = make_binary_tree(arr, n, 0);
    preorder(root);
    cout << "\n\n";

    map<int, vi> mp;
    vertical_order(root, mp, 0);

    for (map<int, vi>::iterator i = mp.begin(); i != mp.end(); i++)
        for (int j = 0; j < i->second.size(); j++)
            cout << i->second[j] << " ";
}