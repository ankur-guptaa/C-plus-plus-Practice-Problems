#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int vertex, vector<int> adj[], int node)
{
    bool check[vertex + 1] = {false};
    queue<int> q;
    q.push(node);
    check[node] = true;
    while (!q.empty())
    {
        cout << q.front() << " ";
        for (vector<int>::iterator i = adj[q.front()].begin(); i != adj[q.front()].end(); i++)
        {
            if (!check[*i])
            {
                q.push(*i);
                check[*i] = true;
            }
        }
        q.pop();
    }
}

void dfs(int node, vector<int> adj[], bool check[], int vertex)
{
    // preorder
    cout << node << " ";
    check[node] = true;
    // inorder
    for (vector<int>::iterator i = adj[node].begin(); i != adj[node].end(); i++)
        if (!check[*i])
            dfs(*i, adj, check, vertex);
    // postorder
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> adj[vertex + 1];
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(vertex, adj, 1);
    cout << endl
         << endl;
    bool check[vertex + 1] = {0};
    dfs(1, adj, check, vertex);
}