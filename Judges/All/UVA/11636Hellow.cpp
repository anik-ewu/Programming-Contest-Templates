#include<iostream>
using namespace std;
int main()
{
    int x=2000,y,z,a,b,c,i=1,k;
    while(x>0)
    {
        cin>>a;
        if(a<0)break;
        y=1;
        k=0;
        while(1)
        {
           if(y>=a)break;
           y=y+y;
           k++;
        }
        cout<<"Case "<<i<<": "<<k<<endl;
        i++;
    }
    return 0;
}
