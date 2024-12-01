#include <iostream>
using namespace std;

bool is_safe(bool **arr, int n, int i, int j)
{
    for (int x = 0; x <= i; x++)
        for (int y = 0; y < n; y++)
        {
            if (x == i || y == j || (x - y) == (i - j) || (i + j) == (x + y))
                if (arr[x][y] == 1)
                    return 0;
        }
    return 1;
}

bool n_queen(int n, bool **arr, int i = 0)
{
    if (n <= i)
        return 1;

    for (int x = 0; x < n; x++)
    {
        if (is_safe(arr, n, i, x))
        {
            arr[i][x] = 1;
            if (n_queen(n, arr, i + 1))
            {
                return 1;
            }
            arr[i][x] = 0;
        }
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter no. of Queens : ";
    cin >> n;
    bool **arr = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new bool[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }

    n_queen(n, arr);

    cout << "You can arrange " << n << " Queens in this manner.\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}