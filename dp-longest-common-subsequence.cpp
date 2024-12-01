#include <iostream>
#include <vector>
using namespace std;

int N = 1e3;
vector<vector<int>> dp(N, vector<int>(N, -1));

int longest_common_subsequence_memoization(string s1, string s2, int n, int m)
{
    if (n <= 0 || m <= 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + longest_common_subsequence_memoization(s1, s2, n - 1, m - 1);

    return dp[n][m] = max(longest_common_subsequence_memoization(s1, s2, n - 1, m), longest_common_subsequence_memoization(s1, s2, n, m - 1));
}

int longest_common_subsequence_tabulation(string s1, string s2, int n, int m)
{
    vector<vector<int>> dpt(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0)
            {
                dpt[i][j] == 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
                dpt[i][j] = 1 + dpt[i - 1][j - 1];
            else
                dpt[i][j] = max(dpt[i - 1][j], dpt[i][j - 1]);
        }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << longest_common_subsequence_memoization(s1, s2, s1.length(), s2.length()) << " " << longest_common_subsequence_tabulation(s1, s2, s1.length(), s2.length());
}