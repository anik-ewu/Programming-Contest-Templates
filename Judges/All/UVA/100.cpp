#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int  a,b,c,d,e,f=0,g,h,i;
    while(cin>>a>>b)
    {
    if(a<b)
    {
        for(i=a; i<=b; i++)
        {
            d=i;
            e=0;
            while(1)
            {
                    if(d==1)
                {
                    e++;
                    break;
                }
                if(d%2==0)
                {
                    d=d/2;
                    e++;
                }
                else
                {
                    d=(d*3)+1;
                    e++;
                }

            }
            if(f<e)
            {
                f=e;
            }

        }
    }
    else
    {
        for(i=b; i<=a; i++)
        {
            d=i;
            e=0;
            while(1)
            {
                if(d==1)
                {
                    e++;
                    break;
                }
                if(d%2==0)
                {
                    d=d/2;
                    e++;
                }
                else
                {
                    d=(d*3)+1;
                    e++;
                }

            }
            if(f<e)
            {
                f=e;
            }

        }
    }
    cout<<a<<' '<<b<<' '<<f<<endl;
    f=0;
 }
 return 0;
}
