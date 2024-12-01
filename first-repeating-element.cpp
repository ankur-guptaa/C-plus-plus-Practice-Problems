// Not giving desire output maybe because of x=1e6+2
#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

int firstrepeatingelement(int *arr, int n)
{
    const int x = 1e6 + 2;
    int *idx=new int[x], minidx = INT_MAX;
    for (int j = 0; j < x; j++)
        idx[j] = -1;
    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] == -1)
            idx[arr[i]] = i;
        else
            minidx = min(minidx, idx[arr[i]]);
    }
    if (minidx == INT_MIN)
        return -1;
    return minidx+1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << firstrepeatingelement(a, n);
}