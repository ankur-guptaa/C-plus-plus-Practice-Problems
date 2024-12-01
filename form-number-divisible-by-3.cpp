#include <iostream>
#include <vector>
using namespace std;

pair<int, int> form_number_divisible(vector<int> arr, int k)
{
    pair<int, int> ans = make_pair(-1, -1);
    int i = 0, sum = 0;
    bool found = false;

    while (i < k)
        sum = sum + arr[i++];
    if (sum % 3 == 0)
    {
        ans = make_pair(0, i - 1);
        found = true;
    }

    while (i < arr.size())
    {
        if (found)
            break;
        sum = sum + arr[i] - arr[i - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
        i++;
    }
    return ans;
}

int main()
{
    vector<int> arr = {84, 23, 45, 12, 56, 82};
    int k = 3;

    pair<int, int> ans = form_number_divisible(arr, k);

    if (ans.first == -1)
        cout << "No such Subarray exists.";
    else
    {
        cout << "The elements in that Subarray are : ";
        for (int i = ans.first; i <= ans.second; i++)
            cout << arr[i] << " ";
    }
}