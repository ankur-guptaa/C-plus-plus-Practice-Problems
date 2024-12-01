#include <iostream>
#include <vector>
using namespace std;

int const N = 1e7;
vector<int> dp(N, -1);

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibonacci(n);
}