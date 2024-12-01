#include <iostream>
#include <vector>
using namespace std;

void change(vector<vector<char>> &arr, int i, int j)
{
    if (arr[i][j] == 'O')
        arr[i][j] = '*';
    else if (arr[i][j] == 'o')
        arr[i][j] = '&';

    int x[] = {0, 0, -1, 1};
    int y[] = {-1, 1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int cx = i + x[k];
        int cy = j + y[k];
        if ((cx >= 0 && cx < arr.size()) && (cy >= 0 && cy < arr[0].size()))
            if (arr[cx][cy] == 'O' || arr[cx][cy] == 'o')
                change(arr, cx, cy);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                if (arr[i][j] == 'o' || arr[i][j] == 'O')
                    change(arr, i, j);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 'o')
                arr[i][j] = 'x';
            else if (arr[i][j] == 'O')
                arr[i][j] = 'X';

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '*')
                arr[i][j] = 'O';
            else if (arr[i][j] == '&')
                arr[i][j] = 'o';

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}