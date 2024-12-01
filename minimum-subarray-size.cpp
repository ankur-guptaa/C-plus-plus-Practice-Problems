#include <iostream>
using namespace std;

int minimum_subarary_size(int arr[], int n, int x)
{
    int start = 0, end = 0, sum = 0, ans = n + 1;
    while (end < n)
    {
        while (sum <= x && end < n)
            sum += arr[end++];

        while (sum > x && start < n)
        {
            ans = min(ans, (end - start));
            sum -= arr[start++];
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    int arr[n] = {1, 4, 45, 6, 10, 19};
    int x = 51;

    int min_length = minimum_subarary_size(arr, n, x);
    if (min_length == n + 1)
        cout << "No such Subarray exists.";
    else
        cout << "The Minimum Length of the Subarray is : " << min_length << ".";
}