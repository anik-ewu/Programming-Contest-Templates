#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,k,x,y,z;
    char a[100000];
    cin>>n;
    getchar();
    while(n>0)
    {
        gets(a);
        x=strlen(a);
        for(i=1; i<x; i+=2)
        {
            y=a[i]-'0';
            for(j=1; j<=y; j++)
                cout<<a[i-1];
        }
        cout<<endl;
        n--;
    }
    return 0;
}
