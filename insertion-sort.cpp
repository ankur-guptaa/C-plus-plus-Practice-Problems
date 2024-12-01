#include <iostream>
using namespace std;

void insertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i], j;
        for (j = i - 1; j >= 0 && arr[j] > curr; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = curr;
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    insertionsort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}