#include <iostream>
#include <vector>
using namespace std;

int N = 1e5;
vector<int> dp(N, -1);

int longest_increasing_subsequence_memoization(vector<int> &arr, int n)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = 1;
    for (int i = 0; i < n; i++)
        if (arr[n] > arr[i])
            dp[n] = max(dp[n], longest_increasing_subsequence_memoization(arr, n - 1) + 1);
        else
            dp[n] = longest_increasing_subsequence_memoization(arr, n - 1);

    return dp[n];
}

int longest_increasing_subsequence_tabulation(vector<int> &arr, int n)
{
    vector<int> dpt(n, 1);
    int ans = INT32_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j])
                dpt[i] = max(dpt[i], dpt[j] + 1);
        ans = max(ans, dpt[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << longest_increasing_subsequence_memoization(arr, n - 1) << " " << longest_increasing_subsequence_tabulation(arr, n - 1);

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
}