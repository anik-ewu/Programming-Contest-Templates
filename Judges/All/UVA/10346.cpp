#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int a,b,c,d,e,i,k,x;
    while(cin>>a>>b)
    {
        d=0;
        e=a;
        while(e>=b)
        {
            c=e%b;
            e=e/b;
            d=d+e;
            e=e+c;

        }
        d=a+d;
        cout<<d<<endl;
    }
    return 0;
}
