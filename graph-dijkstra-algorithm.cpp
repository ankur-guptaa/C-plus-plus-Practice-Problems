#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back(make_pair(x, w));
    }
    int start;
    cin >> start;
    set<pair<int, int>> s;
    s.insert({start, 0});
    dist[start] = 0;
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto i : adj[x.first])
            if (dist[i.first] > dist[x.first] + i.second)
            {
                s.erase({i.first, dist[i.first]});
                dist[i.first] = dist[x.first] + i.second;
                s.insert({i.first, dist[i.first]});
            }
    }

    for (auto i : dist)
        if (i < INT_MAX)
            cout << i << " ";
}