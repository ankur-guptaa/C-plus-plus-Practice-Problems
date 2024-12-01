#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node()
    {
        left = NULL;
        right = NULL;
    }

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void print_preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

void print_inorder(node *root)
{
    if (root == NULL)
        return;
    print_inorder(root->left);
    cout << root->data << " ";
    print_inorder(root->right);
}

void print_postorder(node *root)
{
    if (root == NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int curr, int start, int end)
{
    for (int i = start; i <= end; i++)
        if (inorder[i] == curr)
            return i;
    return -1;
}

node *build_in_preorder(int inorder[], int preorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
        return NULL;
    int curr = preorder[idx];
    idx++;
    node *root = new node(curr);
    if (start == end)
        return root;
    int pos = search(inorder, curr, start, end);
    root->left = build_in_preorder(inorder, preorder, start, pos - 1);
    root->right = build_in_preorder(inorder, preorder, pos + 1, end);
    return root;
}

node *built_in_postorder(int inorder[], int postorder[], int start, int end, int n)
{
    static int idx = n - 1;
    if (start > end)
        return NULL;
    int curr = postorder[idx];
    idx--;
    node *root = new node(curr);
    if (start == end)
        return root;
    int pos = search(inorder, curr, start, end);
    root->right = built_in_postorder(inorder, postorder, pos + 1, end, n);
    root->left = built_in_postorder(inorder, postorder, start, pos - 1, n);
    return root;
}

void level_oreder_traversal(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        {
            if (q.front() == NULL)
            {
                q.pop();
                if (q.empty())
                    return;
                q.push(NULL);
            }
            else
            {
                cout << q.front()->data << " ";
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }
        }
    }
}

int count_nodes(node *root)
{
    if (root == NULL)
        return 0;
    return (count_nodes(root->left) + count_nodes(root->right) + 1);
}

int calculate_diameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldiameter = calculate_diameter(root->left, &lh);
    int rdiameter = calculate_diameter(root->right, &rh);
    int currdiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currdiameter, max(ldiameter, rdiameter));
}

void sum_replacement(node *root)
{
    if (root == NULL)
        return;
    sum_replacement(root->left);
    sum_replacement(root->right);
    if (root->left != NULL)
        root->data += root->left->data;
    if (root->right != NULL)
        root->data += root->right->data;
}

bool is_balanced(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    int lh = 0, rh = 0;
    if (is_balanced(root->left, &lh) == false)
        return false;
    if (is_balanced(root->right, &rh) == false)
        return false;
    *height = max(lh, rh) + 1;
    if (((lh - rh) == -1) || ((lh - rh) == 0) || ((lh - rh) == 1))
        return true;
    else
        return false;
}

void right_view(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            if (i == n - 1)
                cout << q.front()->data << " ";
            q.pop();
        }
    }
}

void left_view(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            if (i == 0)
                cout << q.front()->data << " ";
            q.pop();
        }
    }
}

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);

    if (left == NULL && right == NULL)
        return NULL;
    else if (left != NULL && right != NULL)
        return root;
    else if (left != NULL)
        return left;
    else
        return right;
}

int find_distance(node *root, int n, int distance)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
        return distance;

    int left = find_distance(root->left, n, distance + 1);
    if (left != -1)
        return left;
    return find_distance(root->right, n, distance + 1);
}

int shortest_distance_between_nodes(node *root, int n1, int n2)
{
    node *LCA = lca(root, n1, n2);

    int d1 = find_distance(LCA, n1, 0);
    int d2 = find_distance(LCA, n2, 0);

    return (d1 + d2);
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

    while (1)
    {
        int t;
        cout << "\n\t\t 1. For Preorder Traversal";
        cout << "\n\t\t 2. For Inorder Traversal";
        cout << "\n\t\t 3. For Postorder Traversal";
        cout << "\n\t\t 4. To Built the Tree from Inorder and Preorder";
        cout << "\n\t\t 5. To Built the Tree from Inorder and Postorder";
        cout << "\n\t\t 6. For Level Order Traversal";
        cout << "\n\t\t 7. For Count of Nodes";
        cout << "\n\t\t 8. Calculate the Diameter of Binary Tree";
        cout << "\n\t\t 9. For Sum Replacement in Binary Tree";
        cout << "\n\t\t10. To check Balanced Tree or not";
        cout << "\n\t\t11. For Right View";
        cout << "\n\t\t12. For Left View";
        cout << "\n\t\t13. To find Shortest Distance Between 2 Nodes";
        cout << "\n\t\t14. To Exit";
        cout << "\n\tEnter your choice : ";
        cin >> t;
        switch (t)
        {
        case 1:
            cout << endl;
            print_preorder(root);
            break;
        case 2:
            cout << endl;
            print_inorder(root);
            break;
        case 3:
            cout << endl;
            print_postorder(root);
            break;
        case 4:
        {
            int n;
            cout << "Enter the Number of Elements : ";
            cin >> n;
            int inorder[n], preorder[n];
            cout << "Enter the elements of Inorder : ";
            for (int i = 0; i < n; i++)
                cin >> inorder[i];
            cout << "Enter the elements of Preorder : ";
            for (int i = 0; i < n; i++)
                cin >> preorder[i];
            node *root1 = build_in_preorder(inorder, preorder, 0, n - 1);
            print_inorder(root1);
            break;
        }
        case 5:
        {
            int n;
            cout << "Enter the Number of Elements : ";
            cin >> n;
            int inorder[n], postorder[n];
            cout << "Enter the elements of Inorder : ";
            for (int i = 0; i < n; i++)
                cin >> inorder[i];
            cout << "Enter the elements of Postorder : ";
            for (int i = 0; i < n; i++)
                cin >> postorder[i];
            node *root2 = built_in_postorder(inorder, postorder, 0, n - 1, n);
            print_inorder(root2);
            break;
        }
        case 6:
            cout << endl;
            level_oreder_traversal(root);
            break;
        case 7:
            cout << count_nodes(root);
            break;
        case 8:
        {
            int height = 0;
            cout << calculate_diameter(root, &height);
            break;
        }
        case 9:
            sum_replacement(root);
            break;
        case 10:
        {
            int height = 0;
            if (is_balanced(root, &height) == true)
                cout << "Balanced Binary Tree\n";
            else
                cout << "Unbalanced Binary Tree\n";
            break;
        }
        case 11:
            right_view(root);
            break;
        case 12:
            left_view(root);
            break;
        case 13:
        {
            int n1, n2;
            cout << "Enter First Node value : ";
            cin >> n1;
            cout << "Enter Second Node value : ";
            cin >> n2;
            int distance = shortest_distance_between_nodes(root, n1, n2);
            cout << "\nThe Shortest Distance Between this Nodes is " << distance << ".\n";
            break;
        }
        case 14:
            return 0;

        default:
            cout << "Please enter correct choice!";
            break;
        }
    }
}