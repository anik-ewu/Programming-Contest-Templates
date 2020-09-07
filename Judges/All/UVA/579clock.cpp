#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main()
{
    double a,b,c,i,j,n,m;
    double d;
    char xx;
    while(cin>>a>>xx>>b)
    {
        if(a==0 && b==0)
            break;
        d=(11*b)/2.0;
        c=30*a;
        if(c<d)
            d=d-c;
        else
            d=c-d;
        if(d>180)
            d=360-d;

        printf("%0.3lf\n",d);
    }
    return 0;
}
