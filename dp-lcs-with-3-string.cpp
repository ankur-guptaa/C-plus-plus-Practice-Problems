#include <iostream>
#include <vector>
using namespace std;

int const N = 205;
vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(N, -1)));

int lcs_with_3_string_memoization(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i == 0 || j == 0 || k == 0)
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
        return dp[i][j][k] = 1 + lcs_with_3_string_memoization(s1, s2, s3, i - 1, j - 1, k - 1);

    int p = lcs_with_3_string_memoization(s1, s2, s3, i - 1, j, k);
    int q = lcs_with_3_string_memoization(s1, s2, s3, i, j - 1, k);
    int r = lcs_with_3_string_memoization(s1, s2, s3, i, j, k - 1);

    return dp[i][j][k] = max(max(p, q), r);
}

int lcs_with_3_string_tabulation(string &s1, string &s2, string &s3, int i, int j, int k)
{
    int dpt[i + 1][j + 1][k + 1];

    for (int x = 0; x <= i; x++)
        for (int y = 0; y <= j; y++)
            for (int z = 0; z <= k; z++)
            {
                if (x == 0 || y == 0 || z == 0)
                {
                    dp[x][y][z] = 0;
                    continue;
                }
                if (s1[x - 1] == s2[y - 1] && s2[y - 1] == s3[z - 1])
                    dp[x][y][z] = 1 + dp[x - 1][y - 1][z - 1];
                else
                    dp[x][y][z] = max(dp[x - 1][y][z], max(dp[x][y - 1][z], dp[x][y][z - 1]));
            }
    return dp[i][j][k];
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    cout << lcs_with_3_string_memoization(s1, s2, s3, s1.size(), s2.size(), s3.size()) << " ";
    cout << lcs_with_3_string_tabulation(s1, s2, s3, s1.size(), s2.size(), s3.size());
}