#include<iostream>
using namespace std;

void tower_of_hanoi(string scr, string des, string helper, int n)
{
    if(n==0)
    return;

    tower_of_hanoi(scr, helper, des, n-1);
    cout<<"Move Disc from "<<scr<<" to "<<des<<".\n";
    tower_of_hanoi(helper, des, scr, n-1);
}

int main()
{
    string scr, des, helper;
    int s;
    cout<<"Enter Source name ";
    cin>>scr;
    cout<<"Enter Destination name ";
    cin>>des;
    cout<<"Enter Helper name ";
    cin>>helper;
    cout<<"Enter Number of Disc in Source ";
    cin>>s;

    tower_of_hanoi(scr, des, helper, s);
}