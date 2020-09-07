#include<iostream>
using namespace std;
int k=1;
int forwar_d(int i,int n,int *a)
{

    if(i<=n && k==1)
    {

        cout<<a[i]<<' '<<a[n]<<endl;
        forwar_d(i+1,n-1,a);

    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a[5];
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
        forwar_d(1,n,a);
    }
}

