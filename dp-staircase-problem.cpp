#include <iostream>
#include <vector>
using namespace std;

int N = 1e5;
vector<int> dp(N, -1);

int staircase_memoization(int n)
{
    if (n == 0)
        return 1;
    if (n == 1 || n == 2)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = staircase_memoization(n - 1) + staircase_memoization(n - 2) + staircase_memoization(n - 3);
}

int staircase_tabulation(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << staircase_memoization(n) << " " << staircase_tabulation(n);
}