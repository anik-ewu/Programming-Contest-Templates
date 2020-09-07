#include<iostream>
using namespace std;
int main()
{
    int a[15],i,j,k;
    for(i=1; i<=9; i++)
    {
        cin>>a[i];
    }

    j=0;
    for(i=1; i<=9; i++)
    for(j=i+1; j<=9; j++)
    {
        if(a[i]<a[j])
        {
            k=a[i];
            a[i]=a[j];
            a[j]=k;
            j++;
        }
    }
        for(i=1; i<=9; i++)
            cout<<j<<' ';
}
