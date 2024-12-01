#include <iostream>
#include <queue>
using namespace std;

void insert(priority_queue<int, vector<int>> &pqmax, priority_queue<int, vector<int>, greater<int>> &pqmin, int x)
{
    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0)
            pqmax.push(x);
        else
        {
            if (pqmax.top() <= x)
                pqmin.push(x);
            else
                pqmax.push(x);
        }
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            if (pqmax.top() <= x)
                pqmin.push(x);
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmax.push(x);
                pqmin.push(temp);
            }
        }
        else
        {
            if (pqmin.top() >= x)
                pqmax.push(x);
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmin.push(x);
                pqmax.push(temp);
            }
        }
    }
}

double find_median(priority_queue<int, vector<int>> &pqmax, priority_queue<int, vector<int>, greater<int>> &pqmin)
{
    if (pqmax.size() == pqmin.size())
        return (pqmax.top() + pqmin.top()) / 2.0;
    else
    {
        if (pqmax.size() > pqmin.size())
            return pqmax.top();
        else
            return pqmin.top();
    }
}

int main()
{
    priority_queue<int, vector<int>> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;

    insert(pqmax, pqmin, 10);
    cout << find_median(pqmax, pqmin) << " ";
    insert(pqmax, pqmin, 15);
    cout << find_median(pqmax, pqmin) << " ";
    insert(pqmax, pqmin, 21);
    cout << find_median(pqmax, pqmin) << " ";
    insert(pqmax, pqmin, 30);
    cout << find_median(pqmax, pqmin) << " ";
    insert(pqmax, pqmin, 18);
    cout << find_median(pqmax, pqmin) << " ";
    insert(pqmax, pqmin, 19);
    cout << find_median(pqmax, pqmin) << " ";
}