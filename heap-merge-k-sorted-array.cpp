#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define vi vector<int>
#define pi pair<int, int>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int t;
    cin >> t;
    vector<vi> arr(t);
    rep(i, 0, t)
    {
        int n;
        cin >> n;
        arr[i] = vi(n);
        rep(j, 0, n)
                cin >>
            arr[i][j];
    }

    vi curr_idx(t, 1);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vi ans;

    rep(i, 0, t)
        pq.push(make_pair(arr[i][0], i));

    while (!pq.empty())
    {
        ans.push_back(pq.top().ff);
        int k = pq.top().ss;
        pq.pop();
        if (curr_idx[k] < arr[k].size())
            pq.push(make_pair(arr[k][curr_idx[k]++], k));
    }

    rep(i, 0, ans.size())
            cout
        << ans[i] << " ";
}