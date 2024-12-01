#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int largest_word_in_sentence(char arr[], int n)
{
    int curlen = 0, maxlen = 0, i = 0;

    while (i < n)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            maxlen = max(maxlen, curlen);
            curlen = 0;
        }
        else
            curlen++;
        if (arr[i] == '\0')
            break;
            i++;
    }
    return maxlen;
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin.ignore();
    cin.getline(arr, n);
    cin.ignore();

    cout << largest_word_in_sentence(arr, n);
}