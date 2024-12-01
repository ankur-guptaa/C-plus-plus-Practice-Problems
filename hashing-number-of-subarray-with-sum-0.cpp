#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mp[sum]++;
    }

    int ans = 0;
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
        int temp = i->second;
        ans += (temp * (temp - 1) / 2);
        if (i->first == 0)
            ans += i->second;
    }
    cout << ans;
}