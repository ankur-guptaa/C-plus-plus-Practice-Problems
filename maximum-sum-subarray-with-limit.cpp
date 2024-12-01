#include <iostream>
using namespace std;

int maximum_sum_subarray(int arr[], int n, int k, int x)
{
    int start = 0, end;
    int sum = 0, ans = INT32_MIN;

    for (end = 0; end < k; end++)
        sum += arr[end];
    if (sum < x)
        ans = sum;

    while (end < n)
    {
        sum = sum + arr[end] - arr[start];
        end++;
        start++;
        if (sum < x)
            ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    int n = 6;
    int arr[n] = {7, 5, 4, 6, 8, 9};
    int k = 3, x = 20;

    cout << "The Maximum Sum of the Subarray less than " << x << " is : " << maximum_sum_subarray(arr, n, k, x) << ".";
}