#include <iostream>
#include <vector>
using namespace std;

int N = 1e4;
vector<vector<int>> dp(N, vector<int>(N, -1));

int optimal_game_strategy_memoization(vector<int> &arr, int i, int j)
{
    if (i == j)
        return arr[i];
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int l = arr[i] + min(optimal_game_strategy_memoization(arr, i + 2, j), optimal_game_strategy_memoization(arr, i + 1, j - 1));
    int r = arr[j] + min(optimal_game_strategy_memoization(arr, i + 1, j - 1), optimal_game_strategy_memoization(arr, i, j - 2));

    return dp[i][j] = max(l, r);
}

int optimal_game_strategy_tabulation(vector<int> &arr, int i, int j)
{
    int r = 0, n = 0;
    while (i <= j)
    {
        if (arr[i] >= arr[j])
        {
            r += arr[i];
            i++;
        }
        else
        {
            r += arr[j];
            j--;
        }
        if (arr[i] >= arr[j])
            i++;
        else
            j--;
    }
    return r;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << optimal_game_strategy_memoization(arr, 0, n - 1) << " " << optimal_game_strategy_tabulation(arr, 0, n - 1);
}