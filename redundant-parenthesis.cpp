#include <iostream>
#include <stack>
using namespace std;

bool redundant_parenthesis(string str)
{
    int n = str.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%' || str[i] == '^')
            st.push(str[i]);
        else if (str[i] == ')')
        {
            if (st.empty())
                return true;
            if (st.top() == '(')
                return true;
            while (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*' || st.top() == '%' || st.top() == '^')
                st.pop();
            if (st.empty())
                return true;
            st.pop();
        }
    }
    if (!st.empty())
        return true;
    return false;
}

int main()
{
    cout << "Enter any Mathametical Expressiion : ";
    string str;
    cin >> str;
    bool check = redundant_parenthesis(str);
    if (check == true)
        cout << "Yes! Parenthesis can be reduce futher or Expression may not be Balanced.";
    else
        cout << "No! Parenthesis can't be reduced futher.";
}