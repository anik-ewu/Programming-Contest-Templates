#include<iostream>
#include<cstdio>
#include<math.h>
#include<bits\stdc++.h>
using namespace std;
int main()
{
    long long int n,a,c,d,e,f,i,j,k,x,y;
    int b[20];
    while(cin>>n)
    {
        for(i=1; i<=n; i++)
        {
            cin>>a;
            e=0;
            while(1)
            {
                if(a==0){break;}
                b[e]=a%10;
                a=a/10;
                e++;
            }
            x=0;
            for(j=0; j<e; j++)
            {
               // x=pow(b[j],e);//e number of digit;
                //cout<<x<<" ";
                x=x+pow(b[j],e);
            }
            cout<<x<<endl;
        }
    }
    return 0;
}
