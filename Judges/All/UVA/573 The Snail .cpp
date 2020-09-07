#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a,b,c,d,fat,i,j,k,ans,day;
    while(cin>>a>>b>>c>>d)
    {
        if(a==0)
            return 0;
        ans=0;
        day=0;
        i=1;
        fat=(b*d)/100.0;
        while(true)
        {
            day++;
            if(b>0)
                ans+=b;
            if(ans>a)break;
            ans-=c;
            if(ans<0)break;
            b-=fat;
        }
        if(ans<a)
            cout<<"failure on day "<<day<<endl;
        else
            cout<<"success on day "<<day<<endl;
    }
    return 0;
}
