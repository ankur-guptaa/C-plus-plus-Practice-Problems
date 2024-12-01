#include <iostream>
#include <string.h>
using namespace std;

void permute(int arr[], int n, int i = 0)
{
    if (i == n)
    {
        for (int k = 0; k < n; k++)
            cout << arr[k];
        cout << endl;
        return;
    }

    for (int j = i; j < n; j++)
    {
        swap(arr[j], arr[i]);
        permute(arr, n, i + 1);
        swap(arr[j], arr[i]);
    }
}

int main()
{
    int n;
    cout << "Enter total no. of values : ";
    cin >> n;
    int arr[n];
    cout << "Enter that values : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    permute(arr, n);
}