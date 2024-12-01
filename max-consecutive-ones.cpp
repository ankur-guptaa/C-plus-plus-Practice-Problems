// Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
// Return the length of the longest (contiguous) subarray that contains only 1s.
#include <iostream>
using namespace std;

int max_consecutive_ones(int *arr, int n, int k)
{
    int count = 0, start = 0, mx = 0;
    for (int end = 0; end < n; end++)
    {
        if (arr[end] == 0)
            count++;
        while (count > k)
        {
            if (arr[start] == 0)
                count--;
            start++;
        }
        mx = max(mx, end - start + 1);
    }
    return mx;
}

int main()
{
    int n;
    cout << "Enter total numbers of the values : ";
    cin >> n;
    int *arr = new int[n], k;
    cout << "Enter that values :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value of K : ";
    cin >> k;
    int ans = max_consecutive_ones(arr, n, k);
    cout << ans;
}