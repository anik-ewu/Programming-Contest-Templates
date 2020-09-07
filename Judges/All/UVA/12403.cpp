#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char a[15],b[15];
    int n,i,j,k,x;
    cin>>n;
    getchar();
    x=0;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        getchar();
        if(a[0]=='d')
        {
        cin>>k;
        x=x+k;
        }
        else
        {
        cout<<x<<endl;
        }
    }
    return 0;
}
