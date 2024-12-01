#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define rep(i, a, b) for (int i = a; i < b; i++)

const int N = 1e5 + 2;

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vii adjmx(vertex + 1, vi(vertex + 1, 0));
    vi lt[vertex + 1];

    rep(i, 0, edges)
    {
        int x, y;
        cin >> x >> y;
        adjmx[x][y] = 1;
        adjmx[y][x] = 1;
        lt[x].push_back(y);
        lt[y].push_back(x);
    }

    cout << "The Adjacency Matrix of the above graph is : " << endl;
    rep(i, 1, vertex + 1)
    {
        rep(j, 1, vertex + 1)
                cout
            << adjmx[i][j];
        cout << endl;
    }

    cout << "\n\nThe Adjacency List of the above graph is : " << endl;
    rep(i, 1, vertex + 1)
    {
        cout << i << " -> ";
        for (vi ::iterator j = lt[i].begin(); j != lt[i].end(); j++)
            cout
                << *j << " ";
        cout << endl;
    }
}