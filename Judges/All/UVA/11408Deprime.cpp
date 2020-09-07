#include<iostream>
using namespace std;
#define S 10000000
int mark[S+7];
int mark2[S];
int mark3[S];
int siv()
{
    int x,y;
    for(x=4; x<S; x+=2)
        mark[x]=1;
    for(x=3; x*x<S; x+=2)
    {
        if(mark[x]==0)
        {
            for(y=x*x; y<S; y=y+x+x)
                mark[y]=1;
        }
    }
}
int factor()
{
    siv();
    int i,j,sum,x;
    for(i=4; i<1000000; i++)
    {
        sum=0;
        x=i;
        if(mark[i]!=0)
        {
            for(j=2; j<=x; j++)
            {
                if(x%j==0)
                {
                    while(x%j==0)
                    {
                        if(mark3[j]==0)
                        {
                        sum+=j;
                        mark3[j]=-1;
                        }
                        x/=j;
                        if(x<j)break;
                    }
                }
            }
            if(x>1 && mark3[x]==0)
                sum+=x;
                //cout<<sum<<' ';
            if(mark[sum]==0)
                mark2[sum]=1;
            mark3[x]=0;
        }
        for(j=1; j<100; j++)
            mark3[j]=0;
    }
}
int main()
{
    siv();
    factor();
    int a,b,c,d,i,j,k,x,y,z,sum;
    while(cin>>a)
    {
        if(a==0)break;
        cin>>b;
        x=0;
        for(i=a; i<=b; i++)
        {
            if(mark[i]==0)
                x++;
            else if(mark2[i]==1)
                x++;
         }
        cout<<x<<endl;
    }
    return 0;
}










