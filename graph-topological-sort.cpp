#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> adj(vertex);
    vector<int> in_degree(vertex);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_degree[y]++;
    }

    queue<int> pq;
    for (int i = 0; i < vertex; i++)
        if (in_degree[i] == 0)
            pq.push(i);
    int count = 0;
    while (!pq.empty())
    {
        count++;
        int x = pq.front();
        pq.pop();
        cout << x << " ";
        for (vector<int>::iterator i = adj[x].begin(); i != adj[x].end(); i++)
        {
            in_degree[*i]--;
            if (in_degree[*i] == 0)
                pq.push(*i);
        }
    }
}