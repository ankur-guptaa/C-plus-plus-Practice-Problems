#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vii arr(n);
    rep(i, 0, n)
            cin >>
        arr[i].ff >> arr[i].ss;
    int wob;
    cin >> wob;

    sort(arr.begin(), arr.end(), [=](pii a, pii b) -> bool
         {
        double a1=(double)a.ff/a.ss;
        double b1=(double)b.ff/b.ss;
        return a1>b1; });
    int ans = 0;

    rep(i, 0, n)
    {
        if (arr[i].ss <= wob)
        {
            ans += arr[i].ff;
            wob -= arr[i].ss;
        }
        else
        {
            double temp = arr[i].ff / arr[i].ss;
            ans += wob * temp;
            wob = 0;
            break;
        }
    }
    cout << ans;
}