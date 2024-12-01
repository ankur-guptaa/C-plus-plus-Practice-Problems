// Given that all rows are arranged in ascending order from left to right
// And column are also arranged in ascending order form top to bottom
 
#include <iostream>
using namespace std;

void matrix_search(int **arr, int n, int m, int num)
{
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == num)
        {
            cout << "Element Found at " << i + 1 << " row in " << j + 1 << " column";
            return;
        }
        else if (arr[i][j] > num)
            j--;
        else
            i++;
    }
    cout << "Element Not Found";
}

int main()
{
    int n, m, num;
    cin >> n >> m >> num;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    matrix_search(arr, n, m, num);
}