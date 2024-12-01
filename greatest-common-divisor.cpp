#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    int temp = a % b;
    a = b;
    b = temp;
    return gcd(a, b);
}

int main()
{
    int a, b;
    cout << "Enter any two numbers ";
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    cout<<"The Greatest Common Factor of the given two numbers is "<<gcd(a, b)<<".";
}