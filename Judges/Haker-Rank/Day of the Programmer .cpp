#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,i,j,k;
    cin>>a;
    if(a<1918)
    {
        if(a%4==0)
        {
            cout<<"12.09."<<a<<endl;
        }
        else
        {
            cout<<"13.09."<<a<<endl;
        }
    }
    else if(a==1918)
    {
        cout<<"26.09."<<a<<endl;
    }
    else
    {
        if(a%4==0 && a%100!=0 || a%400==0)
        {
            cout<<"12.09."<<a<<endl;
        }
        else
        {
            cout<<"13.09."<<a<<endl;
        }
    }
    return 0;
}
