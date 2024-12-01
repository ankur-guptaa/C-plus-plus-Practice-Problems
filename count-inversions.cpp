// Two elements a[i] and a[j] form an inversion if a[i]>a[j] and i<j.
#include <iostream>
using namespace std;

int merge(int arr[], int f, int mid, int l)
{
    int n1 = mid - f + 1;
    int n2 = l - mid;
    int a[n1], b[n2];
    int inversion = 0;

    for (int i = 0; i < n1; i++)
        a[i] = arr[f + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = f;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
            inversion = inversion + n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inversion;
}

int merge_sort(int arr[], int f, int l)
{
    int inversion = 0;
    if (f < l)
    {
        int mid = (f + l) / 2;
        inversion = inversion + merge_sort(arr, f, mid);
        inversion += merge_sort(arr, mid + 1, l);
        inversion += merge(arr, f, mid, l);
    }
    return inversion;
}

int main()
{
    cout << "Enter no. of elements of an array : ";
    int n;
    cin >> n;
    cout << "Enter that elements one by one :-\n";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int inversion = merge_sort(arr, 0, n - 1);

    cout << "The total no. inversion in the given array are " << inversion << ".";
}