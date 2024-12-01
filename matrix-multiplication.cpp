#include <iostream>
using namespace std;

int **matrix_multiplication(int **arr1, int **arr2, int n, int m, int l)
{
    int **arr3 = new int *[n];
    for (int i = 0; i < n; i++)
        arr3[i] = new int[l];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            int sum = 0;
            for (int k = 0; k < m; k++)
            {
                sum = sum + (arr1[i][k] * arr2[k][j]);
            }
            arr3[i][j] = sum;
        }
    }
    return arr3;
}

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    int **arr1 = new int *[n], **arr2 = new int *[m];
    for (int i = 0; i < n; i++)
        arr1[i] = new int[m];
    for (int i = 0; i < m; i++)
        arr2[i] = new int[l];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr1[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < l; j++)
            cin >> arr2[i][j];

    int **arr3 = new int *[n];
    for (int i = 0; i < n; i++)
        arr3[n] = new int[l];

    arr3 = matrix_multiplication(arr1, arr2, n, m, l);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
            cout << arr3[i][j] << " ";
        cout << endl;
    }
}