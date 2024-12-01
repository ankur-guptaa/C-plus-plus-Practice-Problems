#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trapping_rainwater(vector<int> arr)
{
    int ans = 0, n = arr.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            int t = st.top();
            st.pop();
            if (st.empty())
                break;
            ans = ans + ((i - st.top() - 1) * (min(arr[i], arr[st.top()]) - arr[t]));
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter Number of the elements you want in array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter that elements :\n";
    for (auto &i : arr)
        cin >> i;
    int ans = trapping_rainwater(arr);
    cout << "The total amount of water that can be stored is " << ans << ".";
}