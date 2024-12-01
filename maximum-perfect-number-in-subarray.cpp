#include <iostream>
#include <cmath>
using namespace std;

bool is_perfect(int num)
{
    int sum = 1;
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            if (num / i == i)
                sum += i;
            else
                sum += i + num / i;

    if (sum == num)
        return true;
    return false;
}

int maximum_sum(int arr[], int n, int k)
{
    int res = 0;
    for (int i = 0; i < k; i++)
        res += arr[i];

    int sum = res;
    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];
        res = max(res, sum);
    }
    return res;
}

int maximum_perfect_number(int arr[], int n, int k)
{
    if (k > n)
        return -1;

    for (int i = 0; i < n; i++)
        if (is_perfect(arr[i]))
            arr[i] = 1;
        else
            arr[i] = 0;

    return maximum_sum(arr, n, k);
}

int main()
{
    int n = 8;
    int arr[n] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;

    cout << "The maximum number of perfect numbers in the given size subarray is : " << maximum_perfect_number(arr, n, k);
}