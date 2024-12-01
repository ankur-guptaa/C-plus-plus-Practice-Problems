#include <iostream>
using namespace std;

bool is_possible(int arr[], int n, int m, int mid)
{
    int count = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;

        if (sum + arr[i] > mid)
        {
            sum = arr[i];
            count++;
            if (count > m)
                return false;
        }
        else
            sum += arr[i];
    }
    return true;
}

int minimum_number_of_maximum_pages(int arr[], int n, int m)
{
    if (n < m)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int left = 0, right = sum;
    int ans = INT32_MAX;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (is_possible(arr, n, m, mid))
        {
            right = mid - 1;
            ans = min(ans, mid);
        }
        else
            left = mid + 1;
    }
    // loop for correction in ans, not used in lecture
    while (is_possible(arr, n, m, ans - 1))
        ans--;

    return ans;
}

int main()
{
    int n = 4, m = 2;
    int arr[n] = {12, 34, 67, 90};

    cout << "The minimum number of maximum pages that can be allocated is : " << minimum_number_of_maximum_pages(arr, n, m) << ".";
}