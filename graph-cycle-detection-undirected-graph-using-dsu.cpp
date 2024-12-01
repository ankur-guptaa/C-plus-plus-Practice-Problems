#include <iostream>
#include <vector>
using namespace std;

int const N = 1e5 + 6;
vector<int> parent(N);
vector<int> size(N);
vector<vector<int>> edges;

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
    return;
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
        size[a] += size[b];
    }
}

int main()
{
    for (int i = 0; i < N; i++)
        make_set(i);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    bool cycle = false;
    for (auto i : edges)
    {
        int a = find_set(i[0]);
        int b = find_set(i[1]);
        if (a == b)
            cycle = true;
        else
            union_set(a, b);
    }
    if (cycle)
        cout << "Cycle is present in the Graph.";
    else
        cout << "Graph doesnot contain any cycle.";
}