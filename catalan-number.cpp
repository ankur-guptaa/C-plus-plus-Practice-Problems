#include <iostream>
using namespace std;

int catalan(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans + (catalan(i) * catalan(n - i - 1));

    return ans;
}

int main()
{
    int n;
    cout << "Enter any number : ";
    cin >> n;

    for (int i = 0; i <= n; i++)
        cout << catalan(i) << " ";
}