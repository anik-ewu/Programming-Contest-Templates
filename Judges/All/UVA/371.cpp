#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long long int i,j,k,l,m,a,b,x,y,c,e,f;
    while(cin>>a>>b)
    {
        if(a==0 && b==0)
        {
            break;
        }
        x=0;
        y=0;
        if(a>b)
        {
            c=a;
            a=b;
            b=c;
        }
        for(i=a; i<=b; i++)
        {
            j=i;
            while(1)
            {
                if(j%2==0)
                {
                    j=j/2;
                }
                else if(j%2!=0)
                {
                    j=(j*3)+1;
                }
                y++;
                if(j==1)
                {
                    break;
                }
            }
            if(x<y)
            {
                x=y;
                l=i;
            }
            y=0;
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<l<<" generates the longest sequence of "<<x<<" values."<<endl;
    }
    return 0;
}
