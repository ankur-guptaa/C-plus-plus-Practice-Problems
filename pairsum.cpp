#include <iostream>
using namespace std;

void pairsum(int arr[], int n, int sum)
{
    int high = n - 1, low = 0;
    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            cout << "Elements Found at Positions " << low + 1 << " & " << high + 1;
            return;
        }
        else if (arr[low] + arr[high] < sum)
            low++;
        else
            high--;
    }
    cout << "Elements not Found.";
    return;
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    pairsum(a, n, sum);
}