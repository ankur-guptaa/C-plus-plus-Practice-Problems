#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largest_rectangle_under_histogram(vector<int> arr)
{
    stack<int> st;
    int n = arr.size();
    int ans = 0, i = 0;
    arr.push_back(0);
    while (i < n)
    {
        while (!st.empty() and arr[st.top()] > arr[i])
        {
            int t = st.top();
            int h = arr[t];
            st.pop();
            if (st.empty())
                ans = max(ans, h * i);
            else
                ans = max(ans, h * (i - st.top() - 1));
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the total Number of Elements : ";
    cin >> n;
    vector<int> arr;
    cout << "Enter that Values : \n";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "The Rectangle of Maximum Area that can fit into this is : " << largest_rectangle_under_histogram(arr) << ".";
}