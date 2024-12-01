#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        if(j==0 || j==i)
        cout<<"*";
        else
        cout<<" ";

        for(int j=(n-i-1)*2; j>0; j--)
        cout<<" ";

        for(int j=0; j<=i; j++)
        if(j==0 || j==i)
        cout<<"*";
        else
        cout<<" ";

        cout<<endl;
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        if(j==0 || j==i)
        cout<<"*";
        else
        cout<<" ";

        for(int j=(n-i-1)*2; j>0; j--)
        cout<<" ";

        for(int j=0; j<=i; j++)
        if(j==0 || j==i)
        cout<<"*";
        else
        cout<<" ";

        cout<<endl;
    }
    return 0;
}