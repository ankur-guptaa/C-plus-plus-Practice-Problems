#include <iostream>
#include <vector>
using namespace std;

bool is_cycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stack)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;
        for (vector<int>::iterator i = adj[src].begin(); i != adj[src].end(); i++)
        {
            if (!visited[*i] && is_cycle(*i, adj, visited, stack))
                return true;
            if (stack[*i])
                return true;
        }
    }
    stack[src] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<bool> visited(n + 1, false);
    vector<bool> stack(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!visited[i] && is_cycle(i, adj, visited, stack))
        {
            cout << "Cycle is present.";
            return 0;
        }
    cout << "Cycle is not present.";
}