// Unsolved
#include <iostream>
#include <math.h>
using namespace std;

void counting_sort(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 0; i < n; i++)
        mx = max(arr[i], mx);

    int count[mx] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]] = count[arr[i]] + 1;

    for (int i = 1; i <= mx; i++)
        count[i] = count[i - 1] + count[i];
    
    int output[n];
    
    for (int i = 0; i < n; i++)
        output[i]=arr[i];
    
    for (int i = 0; i < n; i++)
        arr[--count[arr[i]]] = output[i];
    
}

int main()
{
    cout << "Enter the no. of elements in the array : ";
    int n;
    cin >> n;
    cout << "Enter that elements one by one :-\n";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    counting_sort(arr, n);

    cout << "The elements are arranged in ascending order :-\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}