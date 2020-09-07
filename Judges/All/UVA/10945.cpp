#include<bits/stdc++.h>
using namespace std;
char a[10000000],b[10000000],c[10000000];
int main()
{
    int s,i,j,k,l,m,z;
    while(gets(a))
    {
        if(strcmp(a,"DONE")==0)
            break;
        s=strlen(a);
        j=0;
        z=0;
        for(i=0; i<s; i++)
        {
            if(a[i]>='a' && a[i]<='z' || a[i]>='A' && a[i]<='Z')
            {
                z++;
                if(a[i]>='a' && a[i]<='z')
                {
                    a[i]=a[i]-'a'+'A';
                    b[j++]=a[i];
                }
                else
                    b[j++]=a[i];
            }
        }
            k=0;
            m=0;
            for(i=j-1; i>=0; i--)
                c[m++]=b[i];

            for(i=0; i<j; i++)
            {
                if(b[i]!=c[i])
                {
                    cout<<"Uh oh.."<<endl;
                    k=1;
                    break;
                }
            }
            if(k!=1)
                cout<<"You won't be eaten!"<<endl;
        }
    return 0;
}
