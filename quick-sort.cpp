#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

int partition(int arr[], int f, int l)
{
    int pivot = arr[l];
    int j = f;
    for (int i = f; i < l; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, j);
            j++;
        }
    }
    swap(arr, l, j);
    return j;
}

void quick_sort(int arr[], int f, int l)
{
    if (f < l)
    {
        int pi = partition(arr, f, l);
        quick_sort(arr, f, pi - 1);
        quick_sort(arr, pi + 1, l);
    }
}

int main()
{
    cout << "Enter No. of elements in the array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter that elements :-\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quick_sort(arr, 0, n - 1);

    cout << "The given array is arranged in ascending order : \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}