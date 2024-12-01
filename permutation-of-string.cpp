#include <iostream>
using namespace std;

void permutation_of_string(string str, string ans = "")
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch;
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        string ros = str.substr(0, i) + str.substr(i + 1);
        permutation_of_string(ros, ans + ch);
    }
}

int main()
{
    string str;
    cout << "Enter any string. ";
    cin >> str;
    permutation_of_string(str);
}