#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];
    int x;
    cin >> x;

    sort(arr.begin(), arr.end(), greater<int>());
    int ans = 0;

    rep(i, 0, n)
    {
        ans = ans + (x / arr[i]);
        x = x - ((x / arr[i]) * arr[i]);
    }

    cout << ans;
}