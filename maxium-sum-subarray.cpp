#include <iostream>
#include <limits.h>
using namespace std;

// My Logic
int maximumsum1(int *arr, int n)
{
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

// Given in Notes
int maximumsum2(int *arr, int n)
{
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum = sum + arr[k];
            }
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int prefixsumtechnique(int *arr, int n)
{
    int cumsum[n + 1];
    cumsum[0] = 0;
    for (int i = 1; i <= n; i++)
        cumsum[i] = cumsum[i - 1] + arr[i - 1];

    int maxsum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        maxsum = max(maxsum, cumsum[i]);
        for (int j = 1; j <= i; j++)
        {
            sum = cumsum[i] - cumsum[j - 1];
            maxsum = max(maxsum, sum);
        }
    }
    return maxsum;
}

int kadanesalgorithm(int *arr, int n)
{
    int currsum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum = currsum + arr[i];
        if (currsum < 0)
            currsum = 0;
        maxsum = max(maxsum, currsum);
    }
    return maxsum;
}

int maximumcircularsum(int *arr, int n)
{
    int wrapsum, nonwrapsum = kadanesalgorithm(arr, n), totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + kadanesalgorithm(arr, n);
    return max(wrapsum, nonwrapsum);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << maximumsum1(a, n) << "  " << maximumsum2(a, n) << "  " << prefixsumtechnique(a, n) << "  " << kadanesalgorithm(a, n) << "  " << maximumcircularsum(a, n);
}