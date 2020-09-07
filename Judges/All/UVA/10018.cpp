#include<iostream>
using namespace std;
int main()
{
    long long int n,a,b,c,d[15],i,j,x,y,k,sum;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        b=a;
        x=0;

        while(1)
        {
            c=0;
            while(1)
            {
                if(a==0)break;
                c+=a%10;
                c*=10;
                a/=10;
            }
            c/=10;
            if(c==b)
            {
                cout<<x<<' '<<c<<endl;
                break;
            }
            b=b+c;
            a=b;
            x++;
        }
        n--;
    }
    return 0;

}
