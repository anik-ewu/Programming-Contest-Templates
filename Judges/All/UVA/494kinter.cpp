#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[200000];
    int i,j,k,r,f,x;
    while(gets(a))
    {
        k=strlen(a);
        f=0;
        x=0;
        for(i=0; i<k; i++)
        {
            if(a[i]>='A' && a[i]<='Z' && x==0 || a[i]>='a' && a[i]<='z' && x==0)
            {
                f++;
                x=-1;
            }
            else if(a[i]<'A' || a[i]>'Z' && a[i]<'a' || a[i]>'z')
                x=0;
        }
        cout<<f<<endl;
    }
    return 0;
}


