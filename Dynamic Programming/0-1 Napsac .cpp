#include<bits/stdc++.h>
using namespace std;

vector < int > v,va,vg;


int Knapsac(int n, int w)
{
    if(n==0)
        return 0;
    if(va[n-1]>w)
        return Knapsac(n-1, w);
    else
        return max(va[n-1]+Knapsac(n-1, w-va[n-1]),va[n-1]+Knapsac(n-1, w-va[n-1]),)
           else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );

}



int main()
{
    int a,b,t,i,j,k,n,m,g,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a>>b;
            v.push_back(a);
            va.push_back(b);
        }
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>a;
            vg.push_back(a);
        }








    }





    return 0;
}
