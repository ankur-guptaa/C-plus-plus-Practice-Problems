// To remove the repeating consecutive characters.
#include <iostream>
using namespace std;

void compression_of_string(string str)
{
    string ans;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] != str[i + 1])
            ans += str[i];
        i++;
    }

    cout << ans;
}

int main()
{
    string str;
    cin >> str;

    compression_of_string(str);
}