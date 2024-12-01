#include <iostream>
using namespace std;

int longest_substring_without_repeating_char(string str)
{
    int n = str.length(), mx = 0;
    int arr[257] = {-1}, start = -1;
    for (int end = 0; end < n; end++)
    {
        cout<<mx;
        if (arr[str[end]] > start)
        {
            start = arr[str[end]];
        }
        arr[str[end]] = end;
        mx = max(mx, end - start);
    }
    return mx;
}

int main()
{
    string str;
    cout << "Enter any string : ";
    cin >> str;
    int ans = longest_substring_without_repeating_char(str);
    cout << "The length of longest substring without any repeating character is : " << ans << ".";
}