#include <iostream>
#include <stack>
using namespace std;

bool balanced_parenthesis(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else if (str[i] == ')')
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        else if (str[i] == '}')
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                return false;
        else if (str[i] == ']')
            if (!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string str;
    cout << "Enter any Expression : ";
    cin >> str;
    bool check = balanced_parenthesis(str);
    if (check == true)
        cout << "The Parenthesis in the given Expression are Balanced.";
    else
        cout << "The Parenthesis in the given Expression are not Balanced.";
}