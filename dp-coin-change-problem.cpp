#include <iostream>
#include <vector>
using namespace std;

int const N = 1e4;
vector<vector<int>> dp(N, vector<int>(N, -1));

int coin_change_memoization(vector<int> &arr, int n, int x)
{
    if (x == 0)
        return 1;
    if (x < 0 || n <= 0)
        return 0;

    if (dp[n][x] != -1)
        return dp[n][x];

    return dp[n][x] = coin_change_memoization(arr, n, x - arr[n - 1]) + coin_change_memoization(arr, n - 1, x);
}

int coin_change_tabulation(vector<int> &arr, int n, int x)
{
    vector<int> dpt(x + 1, 0);
    dpt[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= x; j++)
        {
            if (j - arr[i - 1] >= 0)
                dpt[j] += dpt[j - arr[i - 1]];
        }
    return dpt[x];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cin >> x;

    cout << coin_change_memoization(arr, n, x) << " " << coin_change_tabulation(arr, n, x);
}