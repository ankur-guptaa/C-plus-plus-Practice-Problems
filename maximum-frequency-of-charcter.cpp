#include <iostream>
#include <limits.h>
using namespace std;

void max_freq_of_char(string str)
{
    int j = 0, mx = 0, ans[26] = {0};
    while (str[j] != '\0')
    {
        ans[str[j] - 'a']++;
        j++;
    }
        
    for (int i = 1; i < 26; i++)
        if (ans[i] > ans[mx])
            mx = i;

    char a = mx + 'a';
    cout << a;
}

int main()
{
    string str;
    cin >> str;

    max_freq_of_char(str);
}