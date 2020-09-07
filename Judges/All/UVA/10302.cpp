#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int a,b,c,j,k;
    double i;
    while(cin>>a)
    {
        k=0;
        for(i=1; i<=a; i++)
        {
            b=pow(i,3);
            k=k+b;
        }
        cout<<k<<endl;
    }
    return 0;
}
