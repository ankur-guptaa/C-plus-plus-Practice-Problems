#include <iostream>
#include <vector>
using namespace std;

int const N = 1e5;
vector<int> dp0(N, -1), dp1(N, -1);

int count_number_of_binary_string_memoization(int n)
{
    if (n == 1)
    {
        dp0[1] = 1;
        dp1[1] = 1;
        return dp0[1] + dp1[1];
    }

    int ans = count_number_of_binary_string_memoization(n - 1);
    dp0[n] = dp0[n - 1] + dp1[n - 1];
    dp1[n] = dp0[n - 1];
    return dp0[n] + dp1[n];
}

int count_number_of_binary_string_tabulation(int n)
{
    int zero[n + 1], one[n + 1];
    zero[1] = 1;
    one[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        zero[i] = zero[i - 1] + one[i - 1];
        one[i] = zero[i - 1];
    }
    return zero[n] + one[n];
}

int count_number_of_binary_string_through_fibonacci(int n)
{
    int fib[n + 2];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n + 2; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib[n + 1];
}

int main()
{
    int n;
    cin >> n;

    cout << count_number_of_binary_string_tabulation(n) << " " << count_number_of_binary_string_memoization(n) << " " << count_number_of_binary_string_through_fibonacci(n);
}