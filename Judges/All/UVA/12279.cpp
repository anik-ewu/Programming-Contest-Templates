#include<iostream>
using namespace std;
int main()
{
    int a,b,c,i,j,k,n,x,y,p=1;
    n=75;
    while(n>0)
    {
        cin>>a;
        if(a==0){break;}
        x=0;
        y=0;
        for(i=1; i<=a; i++)
        {
            cin>>b;
            if(b!=0){x++;}
            else{y++;}
        }
        k=x-y;
        cout<<"Case "<<p<<": "<<k<<endl;
        n--;
        p++;
    }
    return 0;
}
