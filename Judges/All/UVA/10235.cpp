#include<iostream>
using namespace std;
#define S 10000000
int mark[S+7];
int siv()
{
    int x,y;
    for(x=0; x<S; x++)
        mark[x]=0;
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
    int a,b,c,d,e;
    siv();
    while(cin>>a)
    {
        e=a;
        if(mark[a]==1)
        {
            cout<<a<<" is not prime."<<endl;
        }
        else
        {
            c=0;
            while(1)
            {

                b=a%10;
                c=(c+b)*10;
                a=a/10;
                if(a==0)
                {
                    c=c/10;
                    break;
                }
            }
            if(mark[c]==0 && c!=e)

                cout<<e<<" is emirp."<<endl;
            else
                cout<<e<<" is prime."<<endl;
        }
    }
    return 0;
}
