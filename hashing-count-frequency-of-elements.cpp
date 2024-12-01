#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    rep(i, 0, n)
            cin >>
        arr[i];

    map<int, int> freq;
    rep(i, 0, n)
        freq[arr[i]]++;

    for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
        cout << it->first << " " << it->second << endl;
}