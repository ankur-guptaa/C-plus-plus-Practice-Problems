#include <iostream>
using namespace std;

int first_occurrence(int arr[], int n, int key, int i = 0)
{
    if (i == n)
        return -1;
    if (arr[i] == key)
        return i;
    return first_occurrence(arr, n, key, i + 1);
}

int last_occurrence(int arr[], int n, int key, int i = 0)
{
    if (i == n)
        return -1;
    int restarr = last_occurrence(arr, n, key, i + 1);
    if (restarr != -1)
        return restarr;
    if (arr[i] == key)
        return i;
    else
        return restarr;
}

int main()
{
    int n;
    cout << "Enter number of element ";
    cin >> n;
    int arr[n];
    cout << "Enter that elements ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the value that you want to find in the array ";
    int key;
    cin >> key;
    cout << "Enter your choice\n1. for First Occurrence\n2. for Last Occurrence\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        cout << "The first occurrence of the given element is at " << first_occurrence(arr, n, key) << " index.";
        break;
    case 2:
        cout << "The Last Occurrence of the given element is at " << last_occurrence(arr, n, key) << " index.";
        break;
    default:
        cout << "Enter valid choice.";
        break;
    }
}