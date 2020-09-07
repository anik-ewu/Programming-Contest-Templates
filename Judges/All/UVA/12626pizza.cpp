#include<bits/stdc++.h>
using namespace std;

int pizza(char *a)
{
    int i,c,aa=0,m=0,r=0,g=0,ii=0,t=0,k=0;
    c=strlen(a);
    for(i=0; i<c; i++)
    {
        if(a[i]=='M')
            m++;
        else if(a[i]=='A')
            aa++;
        else if(a[i]=='R')
            r++;
        else if(a[i]=='G')
            g++;
        else if(a[i]=='I')
            ii++;
        else if(a[i]=='T')
            t++;
        if(m>=1 && aa>=3 && r>=2 && g>=1 && ii>=1 && t>=1)
        {
            m-=1;
            aa-=3;
            r-=2;
            g-=1;
            ii-=1;
            t-=1;
            k++;
        }
    }
    return k;
}
int main()
{
    int n,i,j,k,x,y,z,c;
    char a[1000];
    cin>>n;
    getchar();
    while(n>0)
    {
        gets(a);
        cout<<pizza(a)<<endl;
        n--;

    }
    return 0;
}
//one ‘M’,three ‘A’, two ‘R’, one ‘G’, one ‘I’, and one ‘T’.
