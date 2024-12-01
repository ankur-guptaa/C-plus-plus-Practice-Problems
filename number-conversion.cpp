#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

long long decimaltobinary(int a)
{
    int x = 1, y;
    long long ans = 0;
    while (x <= a)
        x *= 2;
    x /= 2;

    while (x > 0)
    {
        y = a / x;
        a = a % x;
        ans = ans * 10 + y;
        x /= 2;
    }
    return ans;
}

int decimaltooctal(int a)
{
    int x = 1, ans = 0;
    while (x <= a)
        x *= 8;
    x /= 8;

    while (x > 0)
    {
        ans = ans * 10 + a / x;
        a %= x;
        x /= 8;
    }
    return ans;
}

string decimaltohexadecimal(int a)
{
    int x = 1;
    string ans;

    while (x <= a)
        x = x * 16;
    x = x / 16;

    while (x > 0)
    {
        switch (a / x)
        {
        case 10:
            ans = ans + 'A';
            break;

        case 11:
            ans = ans + 'B';
            break;

        case 12:
            ans = ans + 'C';
            break;

        case 13:
            ans = ans + 'D';
            break;

        case 14:
            ans = ans + 'E';
            break;

        case 15:
            ans = ans + 'F';
            break;

        default:
            ans = ans + to_string(a / x);
            break;
        }
        a %= x;
        x /= 16;
    }
    return ans;
}

int binarytodecimal(long long a)
{
    int x = 1, ans = 0;
    while (a != 0)
    {
        ans = ans + ((a % 10) * x);
        a /= 10;
        x *= 2;
    }
    return ans;
}

int octaltodecimal(int a)
{
    int x = 1, ans = 0;
    while (a != 0)
    {
        ans = ans + a % 10 * x;
        a /= 10;
        x *= 8;
    }
    return ans;
}

int hexadecimaltodecimal(string a)
{
    int x = 1, ans = 0, i = a.length() - 1;
    while (i >= 0)
    {
        switch (a[i])
        {
        case 'A':
            ans = ans + 10 * x;
            break;

        case 'B':
            ans = ans + 11 * x;
            break;

        case 'C':
            ans = ans + 12 * x;
            break;

        case 'D':
            ans = ans + 13 * x;
            break;

        case 'E':
            ans = ans + 14 * x;
            break;

        case 'F':
            ans = ans + 15 * x;
            break;

        default:
            ans = ans + (a[i] - '0') * x;
            break;
        }
        i--;
        x *= 16;
    }
    return ans;
}

int main()
{
    int a, b;
    long long c;
    string d;

    while (1 == 1)
    {
        cout << "\t\n\nEnter your choice :-" << endl;
        cout << "\t\t1. To Convert Decimal Number to Binary Number\n\t\t2. To Convert Decimal Number to Octal Number\n";
        cout << "\t\t3. To Convert Decimal Number to Hexadecimal Number\n\t\t4. To Convert Binary Number to Decimal Number\n";
        cout << "\t\t5. To Convert Octal Number to Decimal Number\n\t\t6. To Convert Hexadecimal Number to Decimal Number\n";
        cout << "\t\t7. Exit\n";
        cin >> a;

        switch (a)
        {
        case 1:
            cout << "Enter Number ";
            cin >> b;
            cout << decimaltobinary(b);
            getch();
            break;

        case 2:
            cout << "Enter Number ";
            cin >> b;
            cout << decimaltooctal(b);
            getch();
            break;

        case 3:
            cout << "Enter Number ";
            cin >> b;
            cout << decimaltohexadecimal(b);
            getch();
            break;

        case 4:
            cout << "Enter Number ";
            cin >> c;
            cout << binarytodecimal(c);
            getch();
            break;

        case 5:
            cout << "Enter Number ";
            cin >> b;
            cout << octaltodecimal(b);
            getch();
            break;

        case 6:
            cout << "Enter Number ";
            cin >> d;
            cout << hexadecimaltodecimal(d);
            getch();
            break;

        case 7:
            return 0;

        default:
            cout << "Enter from 1 to 7.";
            getch();
            break;
        }
    }
    return 0;
}