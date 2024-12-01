#include <iostream>
#include <math.h>
using namespace std;

void prime_sieve(int n)
{
    int prime[n + 1];
    for (int i = 0; i <= n; i++)
        prime[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == i)
        {
            for (int j = i * i; j <= n; j = j + i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    }
    cout << "The Prime Factorization of the given Number " << n << " is\n";
    while (n != 1)
    {
        cout << prime[n] << " ";
        n = n / prime[n];
    }
}

int main()
{
    int n;
    cout << "Enter the Number upto where you want Prime Number. ";
    cin >> n;
    prime_sieve(n);
}