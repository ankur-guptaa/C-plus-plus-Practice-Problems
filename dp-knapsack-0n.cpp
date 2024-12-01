#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int w;
    cin >> w;

    vector<int> dp(w + 1, 0);
    for (int i = 0; i <= w; i++)
        for (int j = 0; j < n; j++)
            if (i >= wt[j])
                dp[i] = max(dp[i], val[j] + dp[i - wt[j]]);
    cout << dp[w];
}