#include<iostream>
using namespace std;

int longestarithmeticsubarray(int *arr, int n)
{
    int d=arr[1]-arr[0], count=2,ans=2;
    for(int i=2; i<n; i++)
    {
        if(d==arr[i]-arr[i-1])
            count++;
        else
        {
            d=arr[i]-arr[i-1];
            count=2;
        }
        ans=max(ans,count);
}
        return ans;
}

int main()
{
    int t;
    cout<<"Enter no. of test cases  ";
    cin>>t;

    int a[t],b[t];
    for(int i=0; i<t; i++)
    {
        cout<<"Enter no. of element in "<<t<<" test case  ";
        cin>>a[t];
        int c[a[t]];
        for(int j=0; j<a[t]; j++)
        cin>>c[j];

        b[i]=longestarithmeticsubarray(c,a[t]);
    }

    for(int i=0; i<t; i++)
    cout<<"Case # "<<i+1<<" : "<<b[i]<<endl;
}