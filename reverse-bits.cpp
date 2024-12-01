#include <iostream>
using namespace std;

int getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int clearbit(int n, int pos)
{
    return (n & (~(1 << pos)));
}

int setbit(int n, int pos, int value)
{
    n = clearbit(n, pos);
    return (n | (value << pos));
}

int reverse_bits(int n)
{
    int rev = 0;
    while (n)
    {
        rev = rev << 1;
        rev = setbit(rev, 0, getbit(n, 0));
        n = n >> 1;
    }
    return rev;
}

int main()
{
    int n;
    cin>>n;
    cout<<reverse_bits(n);
}