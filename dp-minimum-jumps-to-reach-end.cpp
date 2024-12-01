#include <iostream>
#include <vector>
using namespace std;

int const M = 1e9, N = 1e4;
vector<int> dp(N, M);

int minimum_jumps_to_reach_end_memoization(vector<int> &arr, int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != M)
        return dp[n];

    for (int i = n - 1; i >= 0; i--)
        if (i + arr[i] >= n)
            dp[n] = min(dp[n], minimum_jumps_to_reach_end_memoization(arr, i) + 1);

    return dp[n];
}

int minimum_jumps_to_reach_end_tabulation(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dpt(n, M);
    dpt[0] = 0;
    if (arr[0] <= 0)
        return dpt[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (i <= (j + arr[j]))
                dpt[i] = min(dpt[i], dpt[j] + 1);
    return dpt[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    dp[0] = 0;

    cout << minimum_jumps_to_reach_end_tabulation(arr) << " " << minimum_jumps_to_reach_end_memoization(arr, n - 1);
}