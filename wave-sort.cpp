#include <iostream>
using namespace std;

void wave_sort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i = i + 2)
    {
        if (arr[i] > arr[i - 1])
            swap(arr[i], arr[i - 1]);

        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    cout << "Enter no. of elements you want in an array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter that elements one by one :-\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    wave_sort(arr, n);

    cout << "The elements of the array is arranged in wave form.\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}