#include <iostream>
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
        if (!(i != j && arr[i] == arr[j]))
        {
            swap(arr[i], arr[j]);
            permute(arr, n, i + 1);
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter no. of values : ";
    cin >> n;
    int arr[n];
    cout << "Enter that values : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    permute(arr, n);
}