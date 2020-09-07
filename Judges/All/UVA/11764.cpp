#include<iostream>
using namespace std;
int main()
{
    int i,j,k,n,a,b,c,f,g;
    cin>>n;
    for(i=1; i<=n; i++)
    {

        cin>>a;
        f=0;
        g=0;
        for(j=1; j<=a; j++)
        {
            cin>>b;
            if(j==1)
            {
                c=b;
            }
            if(j!=1)
            {
                if(b>c)
                {
                    c=b;
                    f++;
                }
                if(b<c)
                {
                    c=b;
                    g++;
                }
            }
        }
        cout<<"Case "<<i<<": "<<f<<' '<<g<<endl;



    }
    return 0;
}
