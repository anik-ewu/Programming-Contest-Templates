#include<iostream>
using namespace std;
int main()
{
    int n,x=0,i,j,k;
    double a,b,c,d;
    cin>>n;
    while(n>0)
    {
        cin>>a>>b>>c>>d;
        if((a<=56 && b<=45 && c<=25  || a+b+c<=125)&& d<=7)
        {
            cout<<1<<endl;
            x++;
        }
        else
            cout<<0<<endl;
        n--;
    }
    cout<<x<<endl;
    return 0;
}
//56 cm, width of 45 cm and depth of 25
