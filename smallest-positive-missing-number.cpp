#include <iostream>
using namespace std;

int smallestpositivemissingnumber(int *arr, int n)
{
    int x = 1e6 + 1;
    bool idx[x] = {0};
    for (int i = 0; i < n; i++)
        if (arr[i] >= 0)
            idx[arr[i]] = 1;

    for (int j = 0; j < x; j++)
        if (idx[j] != 1)
            return j;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << smallestpositivemissingnumber(a, n);
}