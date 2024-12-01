#include <iostream>
#include <math.h>
using namespace std;

void prime_sieve(int n)
{
    int prime[n + 1] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j = j + i)
                prime[j] = 1;
        }
    }
    cout << "The Prime Numbers in the given range (form 0 - " << n << ") are\n";
    for (int i = 2; i <= n; i++)
        if (prime[i] == 0)
            cout << i << " ";
}

int main()
{
    int n;
    cout << "Enter the Number upto where you want Prime Number. ";
    cin >> n;
    prime_sieve(n);
}