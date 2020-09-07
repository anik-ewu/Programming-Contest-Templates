#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],n,k,i,j,p=1;

    cin>>n;

    while(n>0)
    {
        for(i=0; i<3; i++)
        {
            cin>>a[i];
        }
        for(i=0; i<3; i++)
            for(j=i+1; j<3; j++)
            {
                if(a[i]<a[j])
                {
                    k=a[i];
                    a[i]=a[j];
                    a[j]=k;
                }
            }
        cout<<"Case "<<p<<": "<<a[1]<<endl;
        n--;
        p++;
    }
    return 0;
}
