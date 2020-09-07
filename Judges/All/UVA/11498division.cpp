#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d,n,m,i,j;
    while(cin>>n)
    {
        if(n==0){break;}
        cin>>a>>b;
        for(i=1; i<=n; i++)
        {
            cin>>c>>d;
            if(a==c || d==b){cout<<"divisa"<<endl;}
            else if(c>=a && d>b){cout<<"NE"<<endl;}
            else if(c<=a && d>b){cout<<"NO"<<endl;}
            else if(c>=a && d<b){cout<<"SE"<<endl;}
            else if(c<=a && d<b){cout<<"SO"<<endl;}

         }
    }
    return 0;
}
