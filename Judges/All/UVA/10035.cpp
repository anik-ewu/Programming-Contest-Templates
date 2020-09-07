#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    long long int a,b,c,d[15],e[15],i,j,k,x;
    while(cin>>a>>b)
    {

        if(a==0 && b==0)
        {
            break;
        }
        x=0;
        if(a<b)
        {
            c=a;
            a=b;
            b=c;
        }
        i=0;
        j=0;
        while(1)
        {
            if(a==0)
                break;
            d[i]=a%10;
            if(b==0)
                e[i]=0;
            else
            {
                e[i]=b%10;
                b=b/10;
            }
            a=a/10;
            k=d[i]+e[i]+j;
            if(k>9)
            {
                j=1;
                x++;
            }
            else
                j=0;
            i++;

        }
        if(x==0)
            cout<<"No carry operation."<<endl;
        else if(x==1)
            cout<<x<<" carry operation."<<endl;
        else
            cout<<x<<" carry operations."<<endl;
    }
    return 0;
}
