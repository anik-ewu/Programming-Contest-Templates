#include<iostream>
using namespace std;
int main()
{
    int a[1000],n,c,d,e,f,x,i,j,k;
    cin>>n;
    while(n>0)
    {

        cin>>k;
        for(i=1; i<=k; i++)
        {
            cin>>a[i];
        }
        x=0;
        for(i=k; i>=2; i--)
            for(j=i-1; j>=1; j--)
            {
                if(a[j]<=a[i])
                {
                    x++;
                }
            }
       cout<<x<<endl;
        n--;
    }
    return 0;
}
//5
//38 111 102 111 177
