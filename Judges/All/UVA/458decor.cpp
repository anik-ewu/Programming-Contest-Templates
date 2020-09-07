#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100000],b[100000],c,d;
    int n,i,j,x,y,k;
    while(gets(a))
    {
        k=strlen(a);
        for(i=0; i<k; i++)
            b[i]=a[i]-7;
        for(i=0; i<k; i++)
        {
            cout<<b[i];
        }
        cout<<endl;
    }
    return 0;

}
