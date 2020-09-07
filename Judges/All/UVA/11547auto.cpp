#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,c[150],b,n,i,j,k,x,y;
    cin>>n;
    while(n>0)
    {
        cin>>a;
        b=a*567;
        b=b/9;
        b=b+7492;
        b=b*235;
        b=b/47;
        b=b-498;
        x=0;
        while(1)
        {
            if(b==0|| x==3)
            {
                break;
            }
            c[x]=b%10;
            b=b/10;
            x++;

        }
        cout<<abs(c[1])<<endl;
        n--;

    }
    return 0;
}
//“Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, then divide
//by 47, then subtract 498.
