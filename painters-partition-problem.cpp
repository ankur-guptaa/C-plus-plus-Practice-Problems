#include <iostream>
using namespace std;

int find_painters(int arr[], int n, int mid)
{
    int painters = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > mid)
        {
            painters++;
            sum = arr[i];
        }
    }
    return painters;
}

int minimum_amount_of_time(int arr[], int n, int p)
{
    int mx = 0, mn = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        mx += arr[i];
        mn = max(mn, arr[i]);
    }

    int low = mn, high = mx;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int numbers_of_painter = find_painters(arr, n, mid);
        if (numbers_of_painter <= p)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main()
{
    int n = 4, p = 2;
    int arr[n] = {10, 20, 30, 40};

    cout << "The Minimum amount of time to paint boards is : " << minimum_amount_of_time(arr, n, p) << ".";
}