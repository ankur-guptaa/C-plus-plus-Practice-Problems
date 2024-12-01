#include <iostream>
#include <string.h>
using namespace std;

string remove_duplicates(string s, string ans = "")
{
    if (s.length() == 0)
        return ans;
        
    if (s[0] == s[1])
        return remove_duplicates(s.substr(1), ans);
    else
        return remove_duplicates(s.substr(1), ans + s[0]);
}

int main()
{
    string s;
    cout << "Enter any string.\n";
    cin >> s;
    cout << remove_duplicates(s);
}