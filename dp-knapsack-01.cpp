#include <iostream>
#include <vector>
using namespace std;

int const N = 1e5;
int dp[N] = {-1};

int knapsack_memoization(vector<int> wt, vector<int> val, int n, int w)
{
    if (w <= 0 || n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    if (w < wt[n])
        return dp[n] = knapsack_memoization(wt, val, n - 1, w);
    return dp[n] = max(knapsack_memoization(wt, val, n - 1, w), knapsack_memoization(wt, val, n - 1, w - wt[n]) + val[n]);
}

int main()
{
    for (int i = 0; i < N; i++)
        dp[i] = -1;
    int n;
    cin >> n;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int w;
    cin >> w;

    cout << knapsack_memoization(wt, val, n, w);
}