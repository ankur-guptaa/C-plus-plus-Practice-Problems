#include <iostream>
#include <vector>
using namespace std;

vector<vector<vector<int>>> dp(2005, vector<vector<int>>(2005, vector<int>(10, -1)));

int k_order_lcs_memoization(string s1, string s2, int k, int i, int j)
{
    if (i <= 0 || j <= 0)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int c1(0), c2(0), c3(0);
    if (s1[i - 1] == s2[j - 1])
        c1 = 1 + k_order_lcs_memoization(s1, s2, k, i - 1, j - 1);
    if (k > 0)
        c2 = 1 + k_order_lcs_memoization(s1, s2, k - 1, i - 1, j - 1);
    c3 = max(k_order_lcs_memoization(s1, s2, k, i - 1, j), k_order_lcs_memoization(s1, s2, k, i, j - 1));

    return dp[i][j][k] = max(max(c1, c2), c3);
}

int k_order_lcs_tabulation(string s1, string s2, int k, int i, int j)
{
    int dp[i + 1][j + 1];

    for (int x = 0; x <= i; x++)
    {
        int z = k;
        for (int y = 0; y <= j; y++)
        {
            if (x == 0 || y == 0)
            {
                dp[x][y] = 0;
                continue;
            }
            if (s1[x - 1] == s2[y - 1])
                dp[x][y] = 1 + dp[x - 1][y - 1];
            else if (z > 0)
            {
                dp[x][y] = 1 + dp[x - 1][y - 1];
                z--;
            }
            else
                dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
        }
    }
    return dp[i][j];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int k;
    cin >> k;

    cout << k_order_lcs_memoization(s1, s2, k, s1.size(), s2.size()) << " " << k_order_lcs_tabulation(s1, s2, k, s1.size(), s2.size());
}