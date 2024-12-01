#include<iostream>

using namespace std;

int main()
{
    int n,ans=1;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=n-i-1; j>0; j--)
            cout<<" ";
        for(int k=0; k<=i; k++)
        {
            if(k==0 ||i==0)
            ans=1;
            else
            ans=ans*(i-k+1)/k;
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}