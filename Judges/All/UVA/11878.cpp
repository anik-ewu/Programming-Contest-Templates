#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f,x=100;
    char p,q,r;
    while(x>0)
    {
        cin>>a;
        cin>>p;
        cin>>b;
        cin>>q;
        cin>>r;
        if(r)
        if(p=='+')
        {
            c=a+b;
            if(c==d)
                f++;
        }
        if(p=='-')
        {
            c=a-b;
            if(c==d)
                f++;
        }
        cout<<f<<endl;
        x--;
    }
    return 0;

}
//1+2=3
//3-1=5
//6+7=?
//99-0=99
