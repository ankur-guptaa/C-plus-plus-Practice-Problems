#include <iostream>
using namespace std;

// Brute Force Solution
// void subarraywithgivensum(int *arr, int n, int sum)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int a = 0;
//         for (int j = i; j < n; j++)
//         {
//             a = a + arr[j];
//             if (a == sum)
//             {
//                 for (int x = i; x <= j; x++)
//                     cout << arr[x] << " ";
//                     return;
//             }
//         }
//     }
//     cout << "Not Founds";
// }

void subarraywithgivensum(int *arr, int n ,int sum)
{
    int s=0,j=0;
    for(int i=0; i<n; i++)
    {
        s=s+arr[i];
        while(s>=sum)
        {
            if(s==sum)
            {
                cout<<"Subarray Found from "<<j+1<<" to "<<i+1<<".";
                return;
            }
            s=s-arr[j];
            j++;
        }
    }
    cout<<"No such Subarray is not Found.";
}

int main()
{
    int n, sum;
    cin >> n >> sum;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    subarraywithgivensum(a, n, sum);
}