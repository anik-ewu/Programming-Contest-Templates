#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,d,e,i,j,k,x,y,z,n,f[5];
    cin>>n;
    while(n>0)
    {
        cin>>a>>b>>c>>d;
        if(a==b==c==d)
            cout<<"square"<<endl;
        else
        {
            f[0]=a;
            f[1]=b;
            f[2]=c;
            f[3]=d;
            sort(f+0,f+4);
            a=f[0];
            b=f[1];
            c=f[2];
            d=f[3];
            if(a==b && c==d)
                cout<<"rectangle"<<endl;
            else if(a+3==b+2==c+1==d)
                cout<<"quadrangle"<<endl;
            else
                cout<<"banana"<<endl;

        }
    }
    return 0;
}
