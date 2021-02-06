#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}


int main()
{
    int a,b,c,d;
    while(cin>>a>>b)
    {
        c=gcd(a,b);
        d=a*b;
        d=d/c;
        cout<<d<<endl;
    }
    return 0;
}
