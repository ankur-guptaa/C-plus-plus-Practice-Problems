#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vi arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];

    map<int, int> mp;
    rep(i, 0, n)
    {
        if (mp[arr[i]] == 0 && mp.size() > k)
            break;
        mp[arr[i]]++;
    }

    vii ans;
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second != 0)
            ans.push_back(make_pair(i->second, i->first));
    }

    sort(ans.begin(), ans.end(), greater<pii>());

    for (vii::iterator i = ans.begin(); i != ans.end(); i++)
        cout << i->second << " " << i->first << endl;
}