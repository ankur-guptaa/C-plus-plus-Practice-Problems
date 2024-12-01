#include <iostream>
#include <math.h>
using namespace std;

int recordbreaker(int *arr, int n)
{
    int mx = arr[0], count = 0, i;
    if (n == 1)
        return 1;
    if (arr[0] > arr[1])
        count++;
    for (i = 1; i < n - 1; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i + 1])
            count++;
        mx = max(arr[i], mx);
    }
    if (arr[n - 1] > mx)
        count++;

    return count;
}

int main()
{
    int t;
    cout << "Enter no. of test cases  ";
    cin >> t;
    int a[t], c[t];
    for (int i = 0; i < t; i++)
    {
        cout << "Enter no. of elements in " << t << " test case  ";
        cin >> a[t];
        int b[a[t]];
        for (int j = 0; j < a[t]; j++)
            cin >> b[j];

        c[i] = recordbreaker(b, a[t]);
    }
    for (int i = 0; i < t; i++)
        cout << "Case # " << i + 1 << " : " << c[i] << endl;
}