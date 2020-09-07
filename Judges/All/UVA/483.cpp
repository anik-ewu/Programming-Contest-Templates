#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,x,y;
    char a[100000],c[100000],d[100000];

    while(gets(a))
    {
        k=strlen(a);
        j=0;
        x=0;
        y=0;
        for(i=0; i<k; i++)
        {
            if(a[i]==' '){
                cout<<a[i];
                y++;}
            else
            {
                x=0;
                while(a[i]!=' ')
                {
                    d[x++]=a[i];
                    i++;
                    if(i==k)break;
                }
                for(j=x-1; j>=0; j--)
                    cout<<d[j];
                i--;
            }
        }
        cout<<endl;
    }
    return 0;
}
