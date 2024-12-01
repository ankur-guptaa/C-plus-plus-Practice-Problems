#include <iostream>
using namespace std;

void spiralorder(int **arr, int n, int m)
{
    int st_row = 0, ed_row = n - 1, st_col = 0, ed_col = m - 1;
    while (st_row <= ed_row && st_col <= ed_col)
    {
        for (int i = st_col; i <= ed_col; i++)
            cout << arr[st_row][i] << " ";
        st_row++;

        for (int i = st_row; i <= ed_row; i++)
            cout << arr[i][ed_col] << " ";
        ed_col--;

        for (int i = ed_col; i >= st_col; i--)
            cout << arr[ed_row][i] << " ";
        ed_row--;

        for (int i = ed_row; i >= st_row; i--)
            cout << arr[i][st_col] << " ";
        st_col++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    spiralorder(a, n, m);
}