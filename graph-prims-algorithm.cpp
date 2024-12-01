// their is some problem (for some test cases it might wrong answer)
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
vector<int> dis;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

void make_set(int v)
{
    parent[v] = v;
}

void prism_algorithm(int curr)
{
    dis[curr] = 0;

    do
    {
        for (auto i : adj)
            if (i[1] == curr && (!visited[i[2]] || dis[curr] > i[0]))
                pq.push({i[0], {i[1], i[2]}});
            else if (i[2] == curr && (!visited[i[1]] || dis[curr] > i[0]))
                pq.push({i[0], {i[2], i[1]}});

        visited[curr] = true;
        int nex = pq.top().second.second;
        if (dis[nex] > pq.top().first)
        {
            parent[nex] = pq.top().second.first;
            dis[nex] = pq.top().first;
        }
        curr = pq.top().second.second;
        pq.pop();
    } while (!pq.empty());
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, u, v});
    }
    visited = vector<bool>(n, false);
    parent = vector<int>(n);
    dis = vector<int>(n, INT_MAX);
    for (int i = 0; i < n; i++)
        make_set(i);

    prism_algorithm(0);

    for (int i = 1; i < n; i++)
        cout << i << " " << parent[i] << endl;

    int sum = 0;
    for (auto i : dis)
        sum += i;
    cout << sum;
}