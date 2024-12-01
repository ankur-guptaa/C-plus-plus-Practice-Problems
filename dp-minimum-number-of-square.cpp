#include <iostream>
#include <vector>
using namespace std;

int const N = 1e7;
vector<int> dp(N, N);

int minimum_number_of_square_memoization(int n)
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    if (dp[n] != N)
        return dp[n];
    for (int i = 1; i * i <= n; i++)
        dp[n] = min(dp[n], minimum_number_of_square_memoization(n - (i * i)) + 1);
    return dp[n];
}

int minimum_number_of_square_tabulation(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    if (dp[n] != N)
        return dp[n];
    for (int i = 4; i <= n; i++)
        dp[i] = min(dp[i], dp[n - (i * i)]);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minimum_number_of_square_memoization(n) << " " << minimum_number_of_square_tabulation(n);
}