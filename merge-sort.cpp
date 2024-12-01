#include <iostream>
using namespace std;

void merge(int arr[], int f, int mid, int l)
{
    int n1 = mid - f + 1;
    int n2 = l - mid;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[f + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int x = 0, y = 0, z = f;
    while (x < n1 && y < n2)
    {
        if (a[x] < b[y])
        {
            arr[z] = a[x];
            x++;
            z++;
        }
        else
        {
            arr[z] = b[y];
            y++;
            z++;
        }
    }
    while (x < n1)
    {
        arr[z] = a[x];
        x++;
        z++;
    }
    while (y < n2)
    {
        arr[z] = b[y];
        y++;
        z++;
    }
}

void merge_sort(int arr[], int f, int l)
{
    if (f < l)
    {
        int mid = (f + l) / 2;
        merge_sort(arr, f, mid);
        merge_sort(arr, mid + 1, l);
        merge(arr, f, mid, l);
    }
}

int main()
{
    cout << "Enter No. of elements in an array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter that elements :-\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    merge_sort(arr, 0, n - 1);

    cout << "The arranged array is (in ascending order) :\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}