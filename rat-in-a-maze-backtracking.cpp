// Have some problems, it run for some set of inputs only
#include <iostream>
using namespace std;

bool rat_in_a_maze(int **arr, int n, int m, int **ans, int i = 0, int j = 0)
{
    if ((i == (n - 1)) && (j == (m - 1)) && (arr[i][j] == true))
    {
        ans[i][j] = 1;
        return 1;
    }

    if ((arr[i][j] == 0) || (i >= n) || (j >= m))
    {
        return 0;
    }

    ans[i][j] = 1;

    if ((rat_in_a_maze(arr, n, m, ans, i + 1, j) == 0) && (rat_in_a_maze(arr, n, m, ans, i, j + 1) == 0))
    {
        ans[i][j] = 0;
        return 0;
    }
    return 1;

    // if(rat_in_a_maze(arr, n, m, ans, i+1, j))
    // {
    //     return 1;
    // }
    // if(rat_in_a_maze(arr, n, m, ans, i, j+1))
    // {
    //     return 1;
    // }
    // ans[i][j]= 0;
    // return 0;
}

int main()
{
    int n, m;
    cout << "Enter the size of maze(n & m) : ";
    cin >> n >> m;
    int **arr = new int *[n];
    int **ans = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        ans[i] = new int[m];
    }

    cout << "Enter 1 for Free Path & 0 for Obstrcal :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            ans[i][j] = 0;
        }
    }

    rat_in_a_maze(arr, n, m, ans);

    cout << "Way to the end of the maze" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}