#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,i,j,k,l,m,n,x;
    while(cin>>a>>b>>c)
    {
        if(a==0 && b==0 && c==0){break;}

         d=a*a; e=b*b; f=c*c;

         i=e-f;
         j=f-e;

         k=d-e;
         l=e-d;

         m=d-f;
         n=f-d;

         if(d==i || d==j || e==m || e==n || f== k || f==l){cout<<"right"<<endl;}
         else{cout<<"wrong"<<endl;}
    }
    return 0;
}
