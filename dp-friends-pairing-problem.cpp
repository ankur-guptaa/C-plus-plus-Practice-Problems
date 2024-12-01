#include <iostream>
#include <vector>
using namespace std;

int N = 1e4;
vector<int> dp(N, -1);

int friends_pairing_problem_memoization(int n)
{
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = friends_pairing_problem_memoization(n - 1) + (n - 1) * friends_pairing_problem_memoization(n - 2);
}

int friends_pairing_problem_tabulation(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << friends_pairing_problem_tabulation(n) << " " << friends_pairing_problem_memoization(n);
}