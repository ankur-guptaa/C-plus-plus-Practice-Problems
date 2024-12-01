#include <iostream>
#include <vector>
using namespace std;

int component_count(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    if (visited[src])
        return 0;

    int ans = 1;
    visited[src] = true;
    for (vector<int>::iterator i = adj[src].begin(); i != adj[src].end(); i++)
        ans = ans + component_count(adj, visited, *i);
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n, false);
    vector<int> component;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            component.push_back(component_count(adj, visited, i));
    }
    for (int i = 0; i < component.size(); i++)
        cout << component[i] << " ";
}