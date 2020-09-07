#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,i,j,x,y,n;
    cin>>n;
    while(n>0)
    {
        cin>>a>>b>>c;
        d=a+b;
        x=0;
        while(d>=c)
        {
            f=d%c;
            x=x+(d/c);
            d=(d/c)+f;
        }
        cout<<x<<endl;

        n--;
    }
    return 0;
}
