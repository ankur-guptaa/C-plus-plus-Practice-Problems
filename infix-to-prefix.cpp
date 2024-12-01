#include <iostream>
#include <stack>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infix_to_prefix(string str)
{
    int len = str.length();
    int i = len-1;
    string ans = "";
    stack<char> st;
    while (i >= 0)
    {
        if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            ans = str[i] + ans;
        }
        else if (str[i] == ')')
            st.push(str[i]);
        else if (str[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                ans = st.top() + ans;
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && (prec(st.top()) > prec(str[i])))
            {
                ans = st.top() + ans;
                st.pop();
            }
            st.push(str[i]);
        }
        i--;
    }
    while (!st.empty())
    {
        ans = st.top() + ans;;
        st.pop();
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter any Infix Expression : ";
    cin >> str;
    cout << "The Prefix Expression is " << infix_to_prefix(str) << " ";
}