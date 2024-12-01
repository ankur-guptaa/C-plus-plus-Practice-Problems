#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool bipartite = true;

void colour(int idx, int curr)
{
    if (color[idx] != -1 && color[idx] != curr)
    {
        bipartite = false;
        return;
    }
    if (color[idx] == curr)
        return;
    color[idx] = curr;
    for (vector<int>::iterator i = adj[idx].begin(); i != adj[idx].end(); i++)
        colour(*i, curr xor 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    color = vector<int>(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1)
            colour(i, 0);

    if (bipartite)
        cout << "The Graph is a Bipartite Graph.";
    else
        cout << "The Graph is not a Bipartite Graph";
}