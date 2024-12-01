#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool is_palindrom(int num)
{
    int temp = num, check = 0;
    while (temp > 0)
    {
        check = (check * 10) + temp % 10;
        temp = temp / 10;
    }
    if (num == check)
        return true;
    return false;
}

int palindromic_concatenation(vector<int> arr, int k)
{
    int sum = 0, i = 0;

    while (i < k)
        sum = (sum * 10) + arr[i++];
    if (is_palindrom(sum))
        return 0;

    while (i < arr.size())
    {
        sum = ((sum % int(pow(10, k - 1))) * 10) + arr[i++];
        if (is_palindrom(sum))
            return i - k;
    }
    return -1;
}

int main()
{
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;

    int ans = palindromic_concatenation(arr, k);
    if (ans == -1)
        cout << "No such Subarray exists.";
    else
    {
        cout << "The elements of that Subarray are : ";
        for (int i = ans; i < k + ans; i++)
            cout << arr[i] << " ";
    }
}