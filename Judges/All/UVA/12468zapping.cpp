#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,i,n;
    n=1;
    while(n<=200)
    {
        cin>>a>>b;
        if(a<0 && b<0){break;}
        if(a<50 && b<50){c=abs(a-b);}
        if(a>50 && b>50){c=abs(a-b);}
        if(a<50 && b>50){c=100-(b-a);}
         cout<<c<<endl;
    }
}
