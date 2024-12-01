#include<iostream>
#include<math.h>
using namespace std;

int knapsack(int wt[], int value[], int n, int wob)
{
    if(n==0 || wob==0)
    return 0;

    if(wt[n-1]>wob)
    return knapsack(wt, value, n-1, wob);

    return max(knapsack(wt, value, n-1, wob), knapsack(wt, value, n-1, wob-wt[n-1])+value[n-1]);
}

int main()
{
    int n;
    cout<<"Enter Number of items : ";
    cin>>n;
    int wt[n], val[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter Weight and Value of item : ";
        cin>>wt[i]>>val[i];
    }
    int wob;
    cout<<"Enter the capacity of bag(Weight) : ";
    cin>>wob;
    cout<<"The maximum value of object that can accommodate in the bag is "<<knapsack(wt, val, n, wob);
}