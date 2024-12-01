#include <iostream>
#include <vector>
using namespace std;

int N = 1e4, M = 1e9;
vector<vector<int>> dp(N, vector<int>(N, -1));

int matrix_chain_multiplication_memoization(vector<int> &arr, int i, int j)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = M;
    for (int k = i; k <= j; k++)
        dp[i][j] = min(dp[i][j], matrix_chain_multiplication_memoization(arr, i, k) + matrix_chain_multiplication_memoization(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]));

    return dp[i][j];
}

int matrix_chain_multiplication_tabulation(vector<int> &arr, int n)
{
    int dpt[n + 1][n + 1];
    for (int i = 1; i < n; i++)
        dpt[i][i] = 0;

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dpt[i][j] = M;
            for (int k = i; k < j; k++)
                dpt[i][j] = min(dpt[i][j], dpt[i][k] + dpt[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]));
        }
    }
    return dpt[1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << matrix_chain_multiplication_memoization(arr, 1, n - 1) << " " << matrix_chain_multiplication_tabulation(arr, n);
}