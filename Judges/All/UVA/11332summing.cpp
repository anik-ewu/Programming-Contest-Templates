#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a;
    int b[15],c,d,n,i,j,x,y;
    while(cin>>a)
    {
        if(a==0)
        {
            break;
        }
        x=0;
        c=0;
        while(1)
        {
            if(a==0 && c>9)
            {
                a=c;
                x=0;
                c=0;
            }
            if(a==0 && c<10)
            {
                break;
            }
            b[x]=a%10;
            a=a/10;
            c=c+b[x];
            x++;
        }
        cout<<c<<endl;

    }
    return 0;
}
