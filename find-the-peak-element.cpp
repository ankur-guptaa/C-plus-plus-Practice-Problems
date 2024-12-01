#include <iostream>
using namespace std;

int find_peak_element(int arr[], int left, int right, int n)
{
    int mid = left + (right - left) / 2;
    if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid] >= arr[mid + 1]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return find_peak_element(arr, left, mid - 1, n);
    else
        return find_peak_element(arr, mid + 1, right, n);
}

int main()
{
    int n = 6;
    int arr[n] = {0, 6, 8, 5, 7, 9};

    cout << "The Peak element index is : " << find_peak_element(arr, 0, n - 1, n);
}