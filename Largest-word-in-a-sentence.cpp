#include <iostream>
using namespace std;

void largest_word_in_a_sentence(char *arr, int n)
{
    int maxlen = 0, curlen = 0, st = 0, maxst = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (maxlen < curlen)
            {
                maxlen = curlen;
                maxst = st;
            }
            st = i + 1;
            curlen = 0;
        }
        else
            curlen++;

        if (arr[i] == '\0')
            break;
    }
    cout << "The length of largest word in the sentence is " << maxlen << " and the word was ";
    for (int i = maxst; i < maxst + maxlen; i++)
        cout << arr[i];
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin.ignore();
    cin.getline(arr, n);
    cin.ignore();

    largest_word_in_a_sentence(arr, n);
}