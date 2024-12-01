#include <iostream>
#include <vector>
using namespace std;

bool is_cycle(vector<vector<int>> &adj, int src, bool visited[], int parent = -1)
{
    visited[src] = true;
    for (vector<int>::iterator i = adj[src].begin(); i != adj[src].end(); i++)
    {
        if (*i != parent)
        {
            if (visited[*i])
                return true;
            if (!visited[*i] && is_cycle(adj, *i, visited, src))
                return true;
        }
    }
    return false;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> adj(vertex + 1);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[vertex + 1] = {false};
    for (int i = 1; i <= vertex; i++)
        if (!visited[i] && is_cycle(adj, i, visited))
        {
            cout << "Cycle is present.";
            return 0;
        }
    cout << "Cycle is not present.";
}