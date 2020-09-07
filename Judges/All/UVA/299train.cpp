#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],b[100],c,i,j,k,x,y,n;
    cin>>n;
    while(n>0)
    {
        cin>>c;
        k=0;
        for(i=1; i<=c; i++)
        {
            cin>>a[i];
        }
        for(i=1; i<=c; i++)
            for(j=i+1; j<=c; j++)
            {
                if(a[i]>a[j])
                {
                    y=a[i];
                    a[i]=a[j];
                    a[j]=y;
                    k++;
                }
            }
            cout<<"Optimal train swapping takes "<<k<<" swaps."<<endl;
            n--;
    }
    return 0;
}
