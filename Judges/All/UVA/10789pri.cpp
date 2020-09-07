#include<bits/stdc++.h>
using namespace std;
#define S 1000000
int mark[S+7];
int cot[1000];
int siv()
{
    int x,y;
    mark[0]=1;
    mark[1]=1;
    for(x=4; x<S; x=x+2)
        mark[x]=1;
    for(x=3; x*x<S; x=x+2)
    {
        if(mark[x]==0)
        {
            for(y=x*x; y<S; y=y+x+x)
                mark[y]=1;
        }
    }
}

int main()
{
    int i,j,k,l,m,x,y=1,n,c;
    char a[10000];
    siv();
    cin>>n;
    getchar();
    while(n>0)
    {
        gets(a);
        c=strlen(a);
        for(i=0; i<c; i++)
        {
            x=int(a[i]);
            cot[x]++;
        }
        cout<<"Case "<<y<<": ";
        m=0;
        y++;

        for(i=1; i<300; i++)
        {
            x=cot[i];
            if(mark[x]==0 && x!=0)
            {
                cout<<char(i);
                m++;
            }
        }
        if(m==0)
            cout<<"empty";
        cout<<endl;
        for(i=1; i<300; i++)
            cot[i]=0;
        n--;

    }
    return 0;
}
