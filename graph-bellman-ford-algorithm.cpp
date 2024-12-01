#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int start;
    cin >> start;
    vector<int> dist(n, INF);
    dist[start] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto j : edges)
        {
            int u = j[0];
            int v = j[1];
            int w = j[2];
            dist[v] = min(dist[v], w + dist[u]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << dist[i] << " ";
}