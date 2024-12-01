// Unsolved
// To find a unique number in an array where all numbers except one, are present thrice.
#include <iostream>
using namespace std;

bool getbit(int n, int pos)
{
    return (n & (1 << pos) != 0);
}

int clearbit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

int setbit(int n, int pos, int value = 1)
{
    n = clearbit(n, pos);
    return (n | (value << pos));
}

int unique_number(int arr[], int n)
{
    int result = 0;

    for (int i = 0; i < 32; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            if (getbit(arr[j], i))
                sum++;

        if (sum % 3 != 0)
            result = setbit(result, i);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << endl
         << unique_number(arr, n);
}