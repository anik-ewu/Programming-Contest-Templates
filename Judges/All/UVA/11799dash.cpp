#include<iostream>
using namespace std;
int main()
{
    int n, a[100000],b,c,x,y,i,j,k,l;
    cin>>n;
    k=1;
    while(n>0)
    {
        cin>>b;
        x=0;
        for(i=1; i<=b; i++)
        {
            cin>>a[i];
            if(a[i]>x){x=a[i];}
        }
        cout<<"Case "<<k<<": "<<x<<endl;
        n--;
        k++;
    }
    return 0;
}
