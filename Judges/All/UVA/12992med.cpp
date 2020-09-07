#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,n,i,j,k;
    while(cin>>n)
    {
        for(i=1; i<=n; i++)
        {
            cin>>a;
            b=a-1;
            c=a+b;
            cout<<"Case #"<<i<<": "<<c<<endl;
        }
    }
    return 0;
}
