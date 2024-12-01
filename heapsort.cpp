#include <iostream>
#include <vector>
using namespace std;

#define vi vector<int>
#define rep1(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (int i = a; i > b; i--)

void heapify(vi &arr, int i, int n)
{
    int max_idx = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && arr[max_idx] < arr[l])
        max_idx = l;
    if (r < n && arr[max_idx] < arr[r])
        max_idx = r;

    if (max_idx != i)
    {
        swap(arr[max_idx], arr[i]);
        heapify(arr, max_idx, n);
    }
}

void heapsort(vi &arr)
{
    int n = arr.size();

    rep2(i, (n / 2) - 1, -1)
        heapify(arr, i, n);

    rep2(i, n - 1, 0)
    {
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

int main()
{
    int n = 6;
    vi arr = {4, 5, 3, 2, 6, 1};

    heapsort(arr);

    rep1(i, 0, n)
    {
        cout << arr[i] << " ";
    }
}