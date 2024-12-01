#include <iostream>
#include <stack>
using namespace std;

void reverse_sentence(string str)
{
    stack<string> st;
    string temp = "";
    int i = 0;
    while (i < str.length())
    {
        while (str[i] != ' ' && i < str.length())
        {
            temp = temp + str[i];
            i++;
        }
        st.push(temp);
        temp = "";
        i++;
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string str;
    cout << "Enter any Sentence : \n";
    getline(cin, str);
    reverse_sentence(str);
}