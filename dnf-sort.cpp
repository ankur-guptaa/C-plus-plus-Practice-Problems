#include <iostream>
using namespace std;

void dnf_sort(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[high], arr[mid]);
            high--;
        }
    }
}

int main()
{
    cout << "Enter no. of elements in an array : ";
    int n;
    cin >> n;
    cout << "Enter that elements which must be only 0 , 1 & 2 only :-\n";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1 && arr[i] != 2)
        {
            cout << "Enter vaild values(0,1,2) :-\n";
            i--;
        }
    }

    dnf_sort(arr, n);

    cout << "The given array is arranged in ascending order.\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
}