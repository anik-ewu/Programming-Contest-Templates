#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1500],d,e,f,i,x=0;
    double b=0,c,l,n,m;
    cin>>f;
    while(f>0)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a[i];
            b=b+a[i];
        }

        c=b/n;

        for(i=1; i<=n; i++)
        {
            if(a[i]>c)
            {
                x++;
            }
        }


        l=(x/n)*100;
        printf("%0.3lf",l);
        cout<<"%"<<endl;
        x=0;
        b=0;
        f--;

    }
    return 0;
}
