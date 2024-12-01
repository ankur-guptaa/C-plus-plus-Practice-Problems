#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int l;
    cin >> l;
    map<int, int> ladd;
    for (int i = 0; i < l; i++)
    {
        int x, y;
        cin >> x >> y;
        ladd[x] = y;
    }
    int s;
    cin >> s;
    map<int, int> snak;
    for (int i = 0; i < s; i++)
    {
        int x, y;
        cin >> x >> y;
        snak[x] = y;
    }

    queue<int> q;
    vector<bool> visited(101, false);
    int move = 0;
    q.push(1);
    visited[1] = true;
    bool found = false;
    while (!q.empty() && !found)
    {
        move++;
        int size = q.size();
        while (size--)
        {
            for (int idx = 1; idx <= 6; idx++)
            {
                if (q.front() + idx <= 100 && ladd[q.front() + idx] && !visited[ladd[q.front() + idx]])
                {
                    visited[ladd[q.front() + idx]] = true;
                    if (ladd[q.front() + idx] == 100)
                        found = true;
                    q.push(ladd[q.front() + idx]);
                }
                else if (q.front() + idx <= 100 && snak[q.front() + idx] && !visited[snak[q.front() + idx]])
                {
                    visited[snak[q.front() + idx]] = true;
                    if (snak[q.front() + idx] == 100)
                        found = true;
                    q.push(snak[q.front() + idx]);
                }
                else if (q.front() + idx <= 100 && !visited[q.front() + idx] && !snak[q.front() + idx] && !ladd[q.front() + idx])
                {
                    visited[q.front() + idx] = true;
                    if (q.front() + idx == 100)
                        found = true;
                    q.push(q.front() + idx);
                }
            }
            q.pop();
        }
    }
    if (found)
        cout << move;
    else
        cout << "-1";
}