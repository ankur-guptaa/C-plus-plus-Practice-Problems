#include <iostream>
#include <vector>
using namespace std;

int const INF = 1e9;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        // adj[v][u] = w;
    }

    vector<vector<int>> dis = adj;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (dis[i][j] == INF)
                cout << "INF ";
            else
                cout << dis[i][j] << " ";
        cout << endl;
    }
}