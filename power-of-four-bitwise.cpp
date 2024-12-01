#include <iostream>
using namespace std;

int count_set_bit(int n)
{
    int count = 0;

    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int power_of_four(int n)
{
    return (!(count_set_bit(n - 1) % 2) && !(n & (n - 1)));
}

int main()
{
    int n;
    cin >> n;
    cout << power_of_four(n);
}