#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first >> arr[i].second;
        int l, p;
        cin >> l >> p;
        for (int i = 0; i < n; i++)
            arr[i].first = l - arr[i].first;

        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>> pq;
        int ans = 0;
        int curr = p;
        bool flag = 1;

        for (int i = 0; i < n; i++)
        {
            if (curr >= l)
                break;

            while (curr < arr[i].first)
            {
                if (pq.empty())
                {
                    flag = 0;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if (!flag)
                break;
            pq.push(arr[i].second);
        }
        if (!flag)
            cout << "-1";
        else
        {
            while (!pq.empty() && curr < l)
            {
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if (curr < l)
                cout << "-1";
            else
                cout << ans;
        }
    }
}