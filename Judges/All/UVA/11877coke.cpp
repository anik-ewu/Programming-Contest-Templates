#include<iostream>
using namespace std;

int coke(int a)
{
    int x=0,y,z=a;
    while(1)
    {
        if(a<3)break;
        x+=a/3;
        y=a%3;
        a=a/3;
        a=a+y;
    }
    if(a==2)
        x=x+1;
    return x+z;
}

int main()
{
    int a;
    while(cin>>a)
    {

        cout<<coke(a)<<endl;
    }
    return 0;
}
