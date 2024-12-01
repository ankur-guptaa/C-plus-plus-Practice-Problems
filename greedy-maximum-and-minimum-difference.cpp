#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int mx = 0, mn = 0;
    for (int i = 0; i < n / 2; i++)
    {
        mx += (arr[(n / 2) + i] - arr[i]);
        mn += (arr[(2 * i) + 1] - arr[2 * i]);
    }
    cout << mn << " " << mx;
}