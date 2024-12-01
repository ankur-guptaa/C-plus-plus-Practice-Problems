#include <iostream>
#include <algorithm>
using namespace std;

bool two_pointer_three_sum(int arr[], int n, int target, int *ans)
{
    int fix, low, high;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        fix = i;
        low = i + 1;
        high = n - 1;
        while (low < high)
        {
            int sum = arr[fix] + arr[low] + arr[high];
            if (sum == target)
            {
                ans[0] = arr[fix];
                ans[1] = arr[low];
                ans[2] = arr[high];
                return true;
            }
            if (sum < target)
                low++;
            else
                high--;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter total number of values : ";
    cin >> n;
    int arr[n], target;
    int *ans = new int[3];
    cout << "Enter that values : \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the sum which you want from these numbers : ";
    cin >> target;
    bool check = two_pointer_three_sum(arr, n, target, ans);
    if (check == true)
    {
        cout << "The values are found in the array which can add up to achieve the target.\nThese values are : ";
        for (int i = 0; i < 3; i++)
            cout << ans[i] << " ";
    }
    else
        cout << "No! such values are found that can be added up to achieve the target.";
}