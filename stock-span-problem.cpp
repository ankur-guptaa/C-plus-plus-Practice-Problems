#include <iostream>
#include <stack>
#include <vector>
// #inlcude <
using namespace std;

vector<int> stock_span(vector<int> arr)
{
    vector<int> ans;
    stack<pair<int, int>> st;
    for (auto i : arr)
    {
        pair<int, int> temp = {i, 1};
        while (!st.empty() && st.top().first <= temp.first)
        {
            temp.second = temp.second + st.top().second;
            st.pop();
        }
        st.push(temp);
        ans.push_back(temp.second);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter total number of values : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter that values : \n";
    for (auto &i : arr)
        cin >> i;
    vector<int> ans = stock_span(arr);
    cout << "The Stock Span is as follow :\n";
    for (int i : ans)
        cout << i << " ";
}