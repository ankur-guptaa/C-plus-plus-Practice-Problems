#include <iostream>
using namespace std;

int search_in_sorted_rotated_array(int arr[], int start, int end, int key)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
        return mid;

    if (arr[start] < arr[mid])
    {
        if (arr[start] <= key && arr[mid] > key)
            return search_in_sorted_rotated_array(arr, start, mid - 1, key);
        else
            return search_in_sorted_rotated_array(arr, mid + 1, end, key);
    }
    else
    {
        if (arr[mid] < key && arr[end] >= key)
            return search_in_sorted_rotated_array(arr, mid + 1, end, key);
        else
            return search_in_sorted_rotated_array(arr, start, mid - 1, key);
    }
}

int main()
{
    int n = 5;
    int arr[n] = {30, 40, 50, 10, 20};
    int key = 10;

    int idx = search_in_sorted_rotated_array(arr, 0, n - 1, key);
    if (idx == -1)
        cout << "Key doesn't exists.";
    else
        cout << "Key is found at index : " << idx << ".";
}