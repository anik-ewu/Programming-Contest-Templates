#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,n,i,j,k;
    while(cin>>n)
    {
        for(k=1; k<=n; k++)
        {
            cin>>a;
            while(b>0)
            {
                for(i=1; i<a; i++)
                {
                    for(j=1; j<a; j++)
                    {
                        if(j<=i)
                        {
                            cout<<'*';
                        }
                    }
                    cout<<endl;
                }
                for(i=1; i<=a; i++)
                {
                    cout<<'*';
                }
                cout<<endl;
                for(i=a-1; i>0; i--)
                {
                    for(j=i; j>0; j--)
                    {
                        if(j<=i)
                        {
                            cout<<'*';
                        }
                    }
                    cout<<endl;
                }
                b--;
                if(b!=0)
                    cout<<endl;

            }
            if(k!=n)
                cout<<endl;
        }
    }
    return 0;
}
