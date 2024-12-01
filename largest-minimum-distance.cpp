#include <iostream>
#include <algorithm>
using namespace std;

bool is_feasible(int arr[], int n, int k, int mid)
{
    int a = arr[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - a >= mid)
        {
            a = arr[i];
            count++;
            if (count >= k)
                return true;
        }
    }
    return false;
}

int largest_minimum_distance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int left = arr[0], right = arr[n - 1];
    int result = -1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (is_feasible(arr, n, k, mid))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid;
    }

    // while (is_feasible(arr, n, k, result + 1))
    //     result--;

    return result;
}

int main()
{
    int n = 7;
    int arr[n] = {3, 25, 17, 9, 14, 20, 11};
    int k = 4;

    cout << "The Largest Minimum Distance is : " << largest_minimum_distance(arr, n, k);
}