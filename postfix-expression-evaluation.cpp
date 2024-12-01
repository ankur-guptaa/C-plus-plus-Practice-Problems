#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int evaluate(int ope1, int ope2, char oper)
{
    switch (oper)
    {
    case '+':
        return ope1 + ope2;
        break;
    case '-':
        return ope1 - ope2;
        break;
    case '*':
        return ope1 * ope2;
        break;
    case '/':
        return ope1 / ope2;
        break;
    case '%':
        return ope1 % ope2;
        break;
    case '^':
        return pow(ope1, ope2);
        break;

    default:
        return 0;
        break;
    }
}

int postfix_evaluation(string str)
{
    int len = str.length();
    stack<int> st;
    int i = 0;
    while (i < len)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            st.push(str[i] - '0');
        }
        else
        {
            int ope2 = st.top();
            st.pop();
            int ope1 = st.top();
            st.pop();
            int ans = evaluate(ope1, ope2, str[i]);
            st.push(ans);
        }
        i++;
    }
    return st.top();
}

int main()
{
    string str;
    cout << "Enter any Postfix Expression : ";
    cin >> str;
    cout << "The Answer of the given Postfix Expression is " << postfix_evaluation(str) << ".";
}