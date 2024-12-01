#include <iostream>
using namespace std;

long long friends_pairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return n;

    return friends_pairing(n - 1) + (friends_pairing(n - 2) * (n - 1));
}

int main()
{
    int n;
    cout << "Enter total number of people : ";
    cin >> n;
    cout << "The total number of way of pairing them leave single are " << friends_pairing(n) << ".";
}