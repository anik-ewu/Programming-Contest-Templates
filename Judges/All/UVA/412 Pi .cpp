#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector < int > v;
    int n,i,j,k,c;
    double a,b,x,y;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(i=1; i<=n; i++)
        {
            cin>>k;
            v.push_back(k);
        }
        x=0;
        k=n*(n-1)/2;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                c=__gcd(v[i],v[j]);
                if(c==1)
                    x++;
            }
        }
        v.clear();
        if(x==0)
            cout<<"No estimate for this data set."<<endl;
        else
        {
            a=6*k;
            b=a/x;
            a=sqrt(b);
            printf("%0.6f\n",a);
        }
    }
    return 0;
}
