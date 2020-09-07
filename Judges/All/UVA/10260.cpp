#include<iostream>
#include<cstring>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
    char a[100];

    int b[100],i,j,k,x,l,m;

    while(scanf("%s",&a)==1)
    {
        x=0;
        k=strlen(a);

        for(i=0; i<k; i++)
        {
            if(a[i]=='B' || a[i]=='F' || a[i]=='P' || a[i]=='V'){b[x]=1;x++;}
            else if(a[i]=='C' || a[i]=='G' || a[i]=='J' || a[i]=='K' || a[i]=='Q' || a[i]=='S' || a[i]=='X' || a[x]=='Z'){b[x]=2;x++;}
            else if(a[i]=='D' || a[i]=='T'){b[x]=3; x++;}
            else if(a[i]=='L'){b[x]=4; x++;}
            else if(a[i]=='M' || a[i]=='N'){b[x]=5; x++;}
            else if(a[i]=='R'){b[x]=6; x++;}
            else{b[x]=0;x++;}

        }
        m=0;
        for(i=0; i<x; i++)
        {
            if(b[i]!=m && b[i]!=0){cout<<b[i];}
            m=b[i];

        }
        cout<<endl;

    }
    return 0;
}

