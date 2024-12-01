#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int curr = 0, mxx = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        mxx = max(curr, mxx);
        if (curr < 0)
            curr = 0;
    }
    cout << mxx;
}