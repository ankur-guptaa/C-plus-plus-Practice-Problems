#include <iostream>
#include <queue>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vi arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];

    priority_queue<int, vector<int>> pq;
    rep(i, 0, n)
        pq.push(arr[i]);

    int sum = 0, count = 0;
    while (!pq.empty())
    {
        sum += pq.top();
        pq.pop();
        count++;
        if (sum >= k)
            break;
    }
    if (sum < k)
        cout << "No such Sequence exists.";
    else
        cout << "The minimum length of the Sequence is : " << count << ".";
}