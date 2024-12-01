#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int, vector<int>> pqg;
    pqg.push(1);
    pqg.push(2);
    pqg.push(3);
    cout << pqg.top() << " ";
    pqg.pop();
    cout << pqg.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pql;
    pql.push(1);
    pql.push(2);
    pql.push(3);
    cout << pql.top() << " ";
    pql.pop();
    cout << pql.top() << endl;
}