#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N);

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] = size[a] + size[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        make_set(i);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int w, u, v;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int cost = 0;
    sort(edges.begin(), edges.end());
    for (auto i : edges)
    {
        int w, u, v;
        w = i[0];
        u = find_set(i[1]);
        v = find_set(i[2]);
        if (u != v)
        {
            union_set(u, v);
            cost = cost + w;
            cout << i[1] << " " << i[2] << endl;
        }
    }
    cout << cost;
}