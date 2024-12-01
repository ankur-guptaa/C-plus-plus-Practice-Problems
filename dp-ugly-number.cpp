#include <iostream>
#include <vector>
using namespace std;

int const N = 1e5;
vector<int> dp(N, -1);

int ugly_number_memoization(int n)
{
    static int c2(0), c3(0), c5(0);
    if (n == 0)
    {
        dp[0] = 1;
        return dp[0];
    }

    ugly_number_memoization(n - 1);
    dp[n] = min(min(2 * dp[c2], 3 * dp[c3]), 5 * dp[c5]);
    if (dp[n] == 2 * dp[c2])
        c2++;
    if (dp[n] == 3 * dp[c3])
        c3++;
    if (dp[n] == 5 * dp[c5])
        c5++;
    return dp[n];
}

int ugly_number_tabulation(int n)
{
    vector<int> dpt(n + 1);
    int c2(0), c3(0), c5(0);
    dpt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dpt[i] = min(min((2 * dpt[c2]), (3 * dpt[c3])), (5 * dpt[c5]));
        if (dpt[i] == (2 * dpt[c2]))
            c2++;
        if (dpt[i] == (3 * dpt[c3]))
            c3++;
        if (dpt[i] == (5 * dpt[c5]))
            c5++;
    }
    return dpt[n - 1];
}

int main()
{
    int n;
    cin >> n;

    cout << ugly_number_tabulation(n) << " " << ugly_number_memoization(n - 1);
}