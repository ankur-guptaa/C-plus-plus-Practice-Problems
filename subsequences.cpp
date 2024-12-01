#include <iostream>
using namespace std;

void subsequences(string s, string ans = "")
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    subsequences(s.substr(1), ans);
    subsequences(s.substr(1), ans + s[0]);
}

int main()
{
    string s;
    cout << "Enter any string.\n";
    cin >> s;
    subsequences(s);
}