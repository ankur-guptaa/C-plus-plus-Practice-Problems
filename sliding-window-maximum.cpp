#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> sliding_window_maximum(int arr[], int k, int n)
{
    int i = 0;
    vector<int> ans;
    deque<int> dq;
    while (i < k)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        i++;
    }
    ans.push_back(arr[dq.front()]);
    while (i < n)
    {
        if (dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
        i++;
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter Number of Elements in the array : ";
    cin >> n;
    int k, arr[n];
    cout << "Enter that Elements one by one : \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the Window Size : ";
    cin >> k;

    vector<int> ans = sliding_window_maximum(arr, k, n);
    cout << "The Maximum Value of the Elements in each Window are :\n";
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
}