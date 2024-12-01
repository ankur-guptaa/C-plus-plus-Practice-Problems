// To find two unique numbers in an array where all numbers except two, are present twice.
#include <iostream>
using namespace std;

int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void two_unique(int arr[], int n)
{
    int xorsum = 0;

    for (int i = 0; i < n; i++)
        xorsum = xorsum ^ arr[i];

    int tempxorsum = 0, j = 0;

    while (getbit(xorsum, j) != 1)
        j++;

    for (int i = 0; i < n; i++)
        if (getbit(arr[i], j) == 1)
            tempxorsum = tempxorsum ^ arr[i];

    cout << tempxorsum << " & " << (xorsum ^ tempxorsum);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    two_unique(arr, n);
}